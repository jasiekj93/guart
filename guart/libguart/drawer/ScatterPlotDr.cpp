#include "ScatterPlot.hpp"
#include <libguart/widget/ScatterPlot.hpp>
#include <libguart/Charset.hpp>

using namespace guart;
using namespace guart::drawer;

ScatterPlot::ScatterPlot(Canvas& canvas)
    : Base(canvas)
{
}

void ScatterPlot::drawWidget(const Drawable& drawable, Canvas& canvas) const
{
    auto& graph = static_cast<const widget::ScatterPlot&>(drawable);
    auto& out = canvas.getOutput(); 

    drawBorder(graph.getPosition(), graph.getDimensions());
    drawBorderTitle(graph.getPosition(), graph.getDimensions(), graph.getTitle());

    auto maxY = (graph.getDimensions().height - 5) / 2;
    auto maxX = (graph.getDimensions().width - 5) / 2;
    
    drawXAxis(drawable, canvas, maxX);
    drawXAxisTitle(drawable, canvas);
    drawYAxis(drawable, canvas, maxY);
    drawYAxisTitle(drawable, canvas);

    if(not drawPoints(drawable, canvas, maxY, maxX))
        drawError(drawable, canvas);
}

void ScatterPlot::drawXAxis(const Drawable& drawable, Canvas& canvas, unsigned int maxX) const
{
    auto& graph = static_cast<const widget::ScatterPlot&>(drawable);
    auto& out = canvas.getOutput();

    Point bottomLeft = {
        graph.getPosition().x + 2,
        graph.getPosition().y + graph.getDimensions().height - 2
    };

    canvas.moveCursor(bottomLeft);
    out << border::LOWER_LEFT << border::HORIZONTAL;

    for(auto i = 0; i < maxX; i++)
        out << border::CROSS << border::HORIZONTAL;

    out << BLACK_RIGHT_POINTING_TRIANGLE;

    canvas.moveCursor(bottomLeft + Point{0, 1});

    for(auto i = 0; i < (maxX + 1); i++)
    {
        out << std::to_string(i);
        if(i < 10) 
            out << ' '; 
    }
}

void ScatterPlot::drawYAxis(const Drawable& drawable, Canvas& canvas, unsigned int maxY) const
{
    auto& graph = static_cast<const widget::ScatterPlot&>(drawable);
    auto& out = canvas.getOutput();

    canvas.moveCursor(graph.getPosition() + Point{2, 2});
    out << BLACK_UP_POINTING_TRIANGLE;
    canvas.moveCursor(graph.getPosition() + Point{2, 3});
    out << border::VERTICAL;

    auto verticalBarDistance = (maxY > 9 ? 3U : 2U);

    for(auto i = 0U; i < maxY; i++)
    {
        canvas.moveCursor(graph.getPosition() + Point{1, (i * 2) + 4});
        out << std::to_string(maxY - i) << border::CROSS;
        canvas.moveCursor(graph.getPosition() + Point{verticalBarDistance, (i * 2) + 5});
        out << border::VERTICAL;
    }
}

bool ScatterPlot::drawPoints(const Drawable &drawable, Canvas &canvas, unsigned int maxY, unsigned int maxX) const
{
    bool hasError = false;
    auto& graph = static_cast<const widget::ScatterPlot&>(drawable);
    auto& out = canvas.getOutput();

    for(auto& point : graph.getItems())
    {
        if((point.x < 0 or point.x > maxX) or (point.y < 0 or point.y > maxY))
        {
            hasError = true;
            continue;
        }

        auto x = graph.getPosition().x + 2 + (point.x * 2);
        auto y = graph.getPosition().y + 4 + ((maxY - point.y) * 2);

        canvas.moveCursor(Point{x, y});
        out << BLACK_CIRCLE;
    }

    return (not hasError);
}

void ScatterPlot::drawXAxisTitle(const Drawable& drawable, Canvas& canvas) const
{
    auto& graph = static_cast<const widget::ScatterPlot&>(drawable);
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

void ScatterPlot::drawYAxisTitle(const Drawable& drawable, Canvas& canvas) const
{
    auto& graph = static_cast<const widget::ScatterPlot&>(drawable);
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

void ScatterPlot::drawError(const Drawable& drawable, Canvas& canvas) const
{
    auto& graph = static_cast<const widget::ScatterPlot&>(drawable);
    auto& out = canvas.getOutput();

    canvas.moveCursor(graph.getPosition() + Point{graph.getDimensions().width - 1, 1});
    out << NO_ENTRY_SIGN;
}
