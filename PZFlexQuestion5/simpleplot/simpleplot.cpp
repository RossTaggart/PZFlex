#include <qapplication.h>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_symbol.h>
#include <qwt_legend.h>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>

int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    QwtPlot plot;
    //changed title of plot to reflect what graph is showing
    plot.setTitle( "Plotting Amplitudes" );
    plot.setCanvasBackground( Qt::white );
    //reduced the axis scale massively to correctly show the data
    plot.setAxisScale( QwtPlot::yLeft, 0.0, 0.07 );
    plot.insertLegend( new QwtLegend() );

    //added axis titles to explain data shown on graph
    plot.setAxisTitle(QwtPlot::xBottom, "Samples");
    plot.setAxisTitle(QwtPlot::yLeft, "Amplitude");

    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->attach( &plot );

    QwtPlotCurve *curve = new QwtPlotCurve();
    //changed title of curve
    curve->setTitle( "Amplitudes" );
    curve->setPen( Qt::blue, 4 ),
    curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );

    //removed symbol in order to show the curve more clearly

    //QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse,
    //    QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 8, 8 ) );
    //curve->setSymbol( symbol );

    QPolygonF points;

    //defined string for file name
    QString fileName = "c:/qwt-6.1.2/examples/simpleplot/output.txt";

    //opens file and makes sure its okay
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return 3;
    }
    //creates text stream based on contents of file
    QTextStream in(&file);

    //defines a point, which we will plot to screen
    QPointF point;
    //counter used for the x coord of point - sample number
    int counter = 0;

    //loops through each line of file
    while (!in.atEnd())
    {
        //reads line
        QString line = in.readLine();
        //qDebug() << line;
        //takes data and add it to string list
        QStringList coords = line.split('\t');

        //sets xcoord to value of counter
        point.setX(counter);
        //increments counter
        counter++;
        //sets ycoord to the amplitude (first number in file)
        point.setY(coords.at(0).toDouble());

        //qDebug() << point;
        //adds point created to list of points
        points << point;
    }
    curve->setSamples( points );

    curve->attach( &plot );

    plot.resize( 600, 400 );
    plot.show();

    return a.exec();
}
