#include "BarGraph.hpp"

#include <algorithm>
#include <iterator>
#include <numeric>

#include <libguart/widget/BarGraph.hpp>
#include <libguart/Charset.hpp>

using namespace guart;
using namespace guart::drawer;

BarGraph::BarGraph(Canvas& canvas)
    : Base(canvas)
{
}

void BarGraph::drawWidget(const Drawable& drawable, Canvas& canvas) const
{
    auto& graph = static_cast<const widget::BarGraph&>(drawable);
    auto& out = canvas.getOutput(); 

    drawBorder(graph.getPosition(), graph.getDimensions());
    drawBorderTitle(graph.getPosition(), graph.getDimensions(), graph.getTitle());

    auto values = getValues(drawable);
    auto labels = getLabels(drawable);

    drawYAxisTitle(drawable, canvas);
    auto yCoordinates = drawYAxis(drawable, canvas, values, getMaxValueWidth(values));
    drawXAxisTitle(drawable, canvas);
    auto xCoordinates = drawXAxis(drawable, canvas, labels, getMaxValueWidth(values));

    if(xCoordinates.size() < labels.size() or 
        yCoordinates.size() < values.size())
    {
        if(yCoordinates.size() < xCoordinates.size())
            xCoordinates.resize(yCoordinates.size());

        drawError(drawable, canvas);
    }

    yCoordinates = sortYCoordinates(values, yCoordinates);
    drawBars(drawable, canvas, xCoordinates, yCoordinates);
}

BarGraph::Coordinates BarGraph::drawXAxis(const Drawable& drawable, Canvas& canvas, const Labels& labels, unsigned int maxValueWidth) const
{
    auto& graph = static_cast<const widget::BarGraph&>(drawable);
    auto& out = canvas.getOutput();

    Point bottomLeft = {
        graph.getPosition().x + maxValueWidth + 1,
        graph.getPosition().y + graph.getDimensions().height - 2
    };

    auto axisLength = graph.getDimensions().width - 3 - maxValueWidth; 
    auto labelsLength = std::accumulate(labels.begin(), labels.end(), 0U, 
        [](unsigned int sum, const std::string& label) { return sum + label.size() + 1; }); 

    if(labelsLength < axisLength)
        axisLength = labelsLength;

    canvas.moveCursor(bottomLeft);
    out << border::LOWER_LEFT << border::HORIZONTAL;

    for(auto i = 0; i < axisLength; i++)
        out << border::HORIZONTAL;
    
    out << BLACK_RIGHT_POINTING_TRIANGLE;

    canvas.moveCursor(bottomLeft + Point{1, 1});
    auto sumLength = 0;
    Coordinates coordinates;

    for(auto i = 0; i < labels.size(); i++)
    {
        const auto& label = labels[i];

        if(sumLength + label.size() > axisLength)
            break;
        
        out << label << ' '; 
        coordinates.push_back(bottomLeft.x + 1 + sumLength + (label.size() / 2));
        sumLength += label.size() + 1; 
    }

    return coordinates;
}

BarGraph::Coordinates BarGraph::drawYAxis(const Drawable& drawable, Canvas& canvas, const Values& v, unsigned int maxValueWidth) const
{
    auto& graph = static_cast<const widget::BarGraph&>(drawable);
    auto& out = canvas.getOutput();

    auto tipPosition = graph.getPosition() + Point{maxValueWidth + 1, 2};

    canvas.moveCursor(tipPosition);
    out << BLACK_UP_POINTING_TRIANGLE;
    canvas.moveCursor(tipPosition + Point{0, 1});
    out << border::VERTICAL;

    auto maxPoints = graph.getDimensions().height - 5; 
    auto values = v;

    if(values.size() > maxPoints)
        values.resize(maxPoints);

    Point::Y step = (maxPoints - values.size()) / (values.size() - 1);
    std::sort(values.begin(), values.end(), std::greater<unsigned int>()); 
    Coordinates coordinates(values.size());
    
    for(auto i = 0U; i < values.size(); i++)
    {
        auto startingPoint = graph.getPosition() + Point{1, (i * (step + 1)) + 3};
        canvas.moveCursor(startingPoint);

        auto spaceCount = maxValueWidth - std::to_string(values[i]).size();

        for(auto i = 0U; i < spaceCount; i++)
            out << ' '; 

        out << std::to_string(values[i]) << border::CROSS;
        
        for(auto j = 1U; j <= step; j++)
        {
            canvas.moveCursor(startingPoint + Point{maxValueWidth, j});
            out << border::VERTICAL;
        }

        coordinates[i] = startingPoint.y;
    }

    return coordinates;
}

void BarGraph::drawXAxisTitle(const Drawable& drawable, Canvas& canvas) const
{
    auto& graph = static_cast<const widget::BarGraph&>(drawable);
    auto& out = canvas.getOutput();
    auto title = graph.getXTitle();

    if(title.empty())
        return;

    auto dimensions = graph.getDimensions();
    auto position = graph.getPosition();
    unsigned int titlePosition = (dimensions.width / 2) - (title.size() / 2);

    canvas.moveCursor({ position.x + titlePosition, position.y + dimensions.height });
    out << title;
}

void BarGraph::drawYAxisTitle(const Drawable& drawable, Canvas& canvas) const
{
    auto& graph = static_cast<const widget::BarGraph&>(drawable);
    auto& out = canvas.getOutput();
    auto title = graph.getYTitle();

    if(title.empty())
        return;

    auto dimensions = graph.getDimensions();
    auto position = graph.getPosition();
    unsigned int titlePosition = (dimensions.width / 2) - (title.size() / 2);

    canvas.moveCursor({ position.x + titlePosition, position.y + 1U });
    out << title;
}

void BarGraph::drawError(const Drawable& drawable, Canvas& canvas) const
{
    auto& graph = static_cast<const widget::BarGraph&>(drawable);
    auto& out = canvas.getOutput();

    canvas.moveCursor(graph.getPosition() + Point{graph.getDimensions().width - 1, 1});
    out << NO_ENTRY_SIGN;
}

void BarGraph::drawBars(const Drawable& drawable, Canvas& canvas, const Coordinates& xCoordinates, const Coordinates& yCoordinates) const
{
    auto& graph = static_cast<const widget::BarGraph&>(drawable);
    auto& out = canvas.getOutput();
    auto maxY = graph.getPosition().y + graph.getDimensions().height - 2;

    for(auto i = 0U; i < xCoordinates.size(); i++)
    {
        auto point = Point{xCoordinates[i], yCoordinates[i]};
        canvas.moveCursor(point);
        out << HALF_LOWER_BLOCK;

        point.y++;
        while(point.y < maxY)
        {
            canvas.moveCursor(point);
            out << FULL_BLOCK;
            point.y++;
        }
    }
}


BarGraph::Values BarGraph::getValues(const Drawable& drawable) const
{
    auto& graph = static_cast<const widget::BarGraph&>(drawable);
    Values values;

    std::transform( 
        graph.getItems().begin(), 
        graph.getItems().end(),
        std::back_inserter(values),
        [](auto &kv){ return kv.second;} 
    );

    return values;
}

BarGraph::Labels BarGraph::getLabels(const Drawable& drawable) const
{
    auto& graph = static_cast<const widget::BarGraph&>(drawable);
    Labels labels;

    std::transform( 
        graph.getItems().begin(), 
        graph.getItems().end(),
        std::back_inserter(labels),
        [](auto &kv){ return kv.first; } 
    );

    return labels;
}

unsigned int BarGraph::getMaxValueWidth(const Values &values) const
{
    auto maxValue = *std::max_element(values.begin(), values.end());
    return std::to_string(maxValue).size();
}

BarGraph::Coordinates BarGraph::sortYCoordinates(const Values& values, const Coordinates &yCoordinates) const
{
    Coordinates result(yCoordinates.size(), 0);
    auto sortedValues = values;
    std::sort(sortedValues.begin(), sortedValues.end(), std::greater<unsigned int>());

    for(auto i = 0U; i < sortedValues.size(); i++)
    {
        auto it = std::find(values.begin(), values.end(), sortedValues[i]);
        if(it != values.end())
        {
            auto index = std::distance(values.begin(), it);
            result[index] = yCoordinates[i];
        }
    }
    return result;
}
