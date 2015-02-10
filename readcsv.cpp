#include <fstream>      /* ifstream         */
#include <iostream>     /* cout             */
#include <cstdlib>      /* count            */
#include <sstream>      /* istringstream    */
#include <vector>       /* vectors          */
//#include <algorithm>
//#include <istream>
//#include <cstdio>

using namespace std;

void get_data(char *fname, vector< vector<float> > &values, char delim)
{
    ifstream data;
    data.open(fname, ifstream::in);
    string line;
    getline(data, line);
    int n = count(line.begin(), line.end(), delim);
    //cout << "Number of columns: " << n +1 << endl;
    values.push_back(vector<float> (n+1,0.0));
    int m = 0;
    string field;
    istringstream s(line);
    while(getline(s,field,delim))
    {
        values.back().at(m) = atof(field.c_str());
        m++;
    }
    while (getline(data, line)){
        values.push_back(vector<float> (n+1,0.0));
        istringstream s(line);
        string field;
        m = 0;
        while (getline(s,field,delim)){
            values.back().at(m) = atof(field.c_str());
            m++;
        }
    }
    data.close(); 
    return;
}

int main(int argc, char *argv[])
{
    char *FNAME;
    FNAME = argv[1];
    vector< vector<float> > DATA;
    char DELIM = ',';
    
    get_data(FNAME, DATA, DELIM);
    
    for (int row=0; row < DATA.size(); row++)
    {
        cout << DATA.at(row).at(0) << "\t" <<
                DATA.at(row).at(1) << "\t" <<
                DATA.at(row).at(2) << endl;
    }
    return 0;
}
