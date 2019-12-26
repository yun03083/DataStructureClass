#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
    char fileName[] = "list";
    strcat(fileName,argv[1]);

    cout << fileName << " generated" << endl;
    ofstream out(fileName);
    out << argv[1] << endl;
    srand((unsigned int)time(0));
    for(int i = 0; i < atoi(argv[1]); i++)
    {
        out << rand()%100 << " ";
    }
    out << endl;
    out << -1 << endl;
    out.close();

    return 0;
}
