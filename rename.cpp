// I named all my files my-file-name.cpp instead of my_file_name.cpp.
// Let's change them programmatically.

#include <iostream>
#include <filesystem>
#include <string>

using namespace std;
using namespace std::filesystem;

int main()
{
  for (const directory_entry &dir : directory_iterator {"."})
    {
      if (is_directory(dir))
      {
        for (const directory_entry &file : directory_iterator{dir})
          {
            string f_name = file.path().string();

            int stem_start = f_name.find_first_of("/") + 1;
            int ext_start = f_name.find_last_of(".") + 1;

            string ext = f_name.substr(ext_start);
            string stem = f_name.substr(stem_start, ext_start - stem_start - 1);
            
            if (ext == "cpp")
            {
              int underscore_i = f_name.find_last_of("/");
              while ((underscore_i = f_name.find('-', underscore_i + 1)) != -1)
                f_name.replace(underscore_i, 1, "_");
              rename(file.path().string(), f_name);
            }
          }
      }
    }


  return 0;
}