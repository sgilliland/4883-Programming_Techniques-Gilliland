// Sarah Gilliland
// UVA 209 - Sunny Side Mountains
// CMPS 4883 - Programming Techniques
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

struct Point
{
    int X;
    int Y;

    // Constructors
    Point() : X{0}, Y{0} {}                 // sets X and Y to 0
    Point(int p1, int p2) : X{p1}, Y{p2} {} // sets X to p1 and Y to p2
};

vector<Point> points; // vector of Point structs

// function comparing two points and returning true if the first is to the right of the second (used for sorting algorithm)
bool compare(Point &a, Point &b)
{
    return b.X < a.X;
}

// prints the sorted points in a pretty format - for debugging
void printPoints()
{
    for (int i = 0; i < points.size(); i++)
    {
        cout << "[" << points[i].X << "," << points[i].Y << "]" << endl;
    }
}

int main()
{
    int Highest, startPoint, x, y, C, N;
    double q, p, dist, heightDiff, peakDiff, Distance;

    cin >> C; // number of cases
    while (C--)
    {
        startPoint = 0; // stays 0 if point is a trough
        Distance = 0;
        Highest = 0;

        cin >> N; // number of points in this case

        while (N--) // read in points and store in vector
        {
            cin >> x >> y;
            points.push_back(Point(x, y));
        }

        // sorting algorithm
        sort(points.begin(), points.end(), compare);

        if (points[0].Y < points[1].Y) // the first point is a trough
        {
            startPoint = 1;
        } // start at the first peak instead

        // do calculations
        for (int i = startPoint; i < points.size(); i++)
        {
            if (points[i].Y >= Highest) // if the sun is touching the peak
            {
                // Declarations to make equation readable
                q = double(points[i].X - points[i - 1].X);
                p = double(points[i].Y - points[i - 1].Y);
                dist = sqrt(pow(q, 2) + pow(p, 2));         // Euclidian distance
                heightDiff = (points[i].Y - Highest);       // height difference
                peakDiff = (points[i].Y - points[i - 1].Y); // difference in distance between 2 peaks

                // Formula: (Euclidian distance) * (height difference) / (difference in distance between 2 peaks)
                Distance += dist * heightDiff / peakDiff;

                //cout << "Length of mountain side is " << sqrt(pow(q, 2) + pow(p, 2)) << endl;
                //cout << "Height difference is " << (points[i].Y - Highest) << endl;
                //cout << "Peak difference is " << (points[i].Y - points[i - 1].Y) << endl;

                Highest = points[i].Y; // Update the highest point
            }
        }
        // printPoints();  // use to debug
        cout << setprecision(2) << fixed << Distance << '\n';
        points.clear();
    }

    return 0;
}