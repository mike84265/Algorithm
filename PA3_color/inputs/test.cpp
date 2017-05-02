#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;
int main(int argc, char** argv)
{
   if (argc < 2) {
      fprintf(stderr, "Error\n");
      exit(1);
   }
   ifstream ifs(argv[1]);
   string str;
   int v1, v2, w, f;
   bool read = false;
   while (1) {
      getline(ifs,str);
      if (ifs.eof())
         break;
      f = sscanf(str.c_str(), "v%d -- v%d [label = \"%d\"];", &v1, &v2, &w);
      printf("f=%d, v1=%d, v2=%d, w=%d, str = %s\n",f,v1,v2,w,str.c_str());
   }
   return 0;
}
