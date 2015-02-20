#include <fstream>      /* ifstream         */
#include <iostream>     /* cout             */
#include <cstdlib>      /* atof             */
#include <sstream>      /* istringstream    */
#include <vector>       /* vectors          */
#include <algorithm>    /* count            */

using namespace std;

void get_data(char *fname, vector< vector<float> > &values, char delim)
{
    //
    // get_data
    //
    // Input:  [fname]  - table data file name
    //         [values] - pointer to empty 2-dim vector to be sized and filled
    //                    with data from fname
    //         [delim]  - single character column delimiter
    //
    // Output: [values] - pointer to mxn vector of data read from fname
    //

    // Opens data file
    ifstream data;
    data.open(fname, ifstream::in);

    // Preps first line of data file to determine number of columns, n
    string line;
    getline(data, line);
    int n = count(line.begin(), line.end(), delim);

    // Read first row in data file
    values.push_back(vector<float> (n+1,0.0));
    int m = 0;
    string field;
    istringstream sline(line);
    while(getline(sline,field,delim))
    {
        values.back().at(m) = atof(field.c_str());
        m++;
    }

    // Loop over the rest of the rows in the file and read in
    while (getline(data, line)){
        values.push_back(vector<float> (n+1,0.0));
        istringstream sline(line);
        string field;
        m = 0;
        while (getline(sline,field,delim)){
            values.back().at(m) = atof(field.c_str());
            m++;
        }
    }

    // Close data file and end
    data.close();
    return;
}

int main(int argc, char *argv[])
{
    //
    // Example implentation:
    //
    // This code will compile using
    // $ g++ readcsv.cpp -o readcsv
    //
    // then run it from the command line using
    // $ readcsv path_to/file.csv
    //

    char *FNAME;
    FNAME = argv[1];

    // Create an empty 2dim vector
    vector< vector<float> > DATA;

    // Set the data file delimiter
    char DELIM = ',';

    // Function call
    get_data(FNAME, DATA, DELIM);

    // Print data file to screen
    // Note: hard coded for Mx3 vector
    for (int row=0; row < DATA.size(); row++)
    {
        cout << DATA.at(row).at(0) << "\t" <<
                DATA.at(row).at(1) << "\t" <<
                DATA.at(row).at(2) << endl;
    }
    return 0;
}
