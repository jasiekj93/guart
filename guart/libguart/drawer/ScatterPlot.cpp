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

    auto maxY = (graph.getDimensions().height - 4) / 2;
    auto maxX = (graph.getDimensions().width - 4) / 2;
    
    drawXAxis(drawable, canvas, maxX);
    drawYAxis(drawable, canvas, maxY);
    drawPoints(drawable, canvas, maxY, maxX);
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

    canvas.moveCursor(bottomLeft + Point{0, 2});

    for(auto i = 0; i < (maxX + 1); i++)
        out << std::to_string(i) << ' ';
}

void ScatterPlot::drawYAxis(const Drawable& drawable, Canvas& canvas, unsigned int maxY) const
{
    auto& graph = static_cast<const widget::ScatterPlot&>(drawable);
    auto& out = canvas.getOutput();

    canvas.moveCursor(graph.getPosition() + Point{2, 1});
    out << BLACK_UP_POINTING_TRIANGLE;
    canvas.moveCursor(graph.getPosition() + Point{2, 2});
    out << border::VERTICAL;

    auto verticalBarDistance = (maxY > 9 ? 3U : 2U);

    for(auto i = 0U; i < maxY; i++)
    {
        canvas.moveCursor(graph.getPosition() + Point{1, (i * 2) + 3});
        out << std::to_string(maxY - i) << border::CROSS;
        canvas.moveCursor(graph.getPosition() + Point{verticalBarDistance, (i * 2) + 4});
        out << border::VERTICAL;
    }
}

void ScatterPlot::drawPoints(const Drawable &drawable, Canvas &canvas, unsigned int maxY, unsigned int maxX) const
{
    auto& graph = static_cast<const widget::ScatterPlot&>(drawable);
    auto& out = canvas.getOutput();

    for(auto& point : graph.getItems())
    {
        if((point.x < 0 or point.x > maxX) or (point.y < 0 or point.y > maxY))
            continue;

        auto x = graph.getPosition().x + 2 + (point.x * 2);
        auto y = graph.getPosition().y + 3 + ((maxY - point.y) * 2);

        if(point.y == 0)
            y -= 1;

        canvas.moveCursor(Point{x, y});
        out << BLACK_CIRCLE;
    }
}
