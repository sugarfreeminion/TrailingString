/************************************************************************
 * Author:      sugarfreeoh
 * Date:        12 March 2016
 * Description: There are two strings: A and B. Print 1 if string B
 *              occurs at the end of string A. Otherwise Print 0
 ***********************************************************************/

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream inputFile;

    inputFile.open(argv[1]);

    if(inputFile.is_open())
    {
        string line;
        string a;
        string b;
        string trailingA;
        size_t delLocation;

        int comp;

        while(getline(inputFile,line))
        {
            delLocation = line.find(',');

            a = line.substr(0,delLocation);
            b = line.substr(delLocation+1,line.size()-delLocation-1);

            //cout << "A: " << a << endl;
            //cout << "B: " << b << endl;
          
            if(b.size()>a.size())
            {
                cout << "0" << endl;
                continue;
            }

            if((a.size()-b.size())>=0)
            {
                trailingA = a.substr(a.size()-b.size());
            }
            else
            {
                trailingA = "";
            }

            //cout << "Trailing A: " << trailingA << "." << endl;

            comp = strcmp(trailingA.c_str(), b.c_str());

            if(comp == 0)
            {
                cout << "1" << endl;
            }
            else
            {
                cout << "0" << endl;
            }
        }

        inputFile.close();
    }

    return 0;
}
