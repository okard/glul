
#include <cstdio>
#include <glul/Glew>

using namespace glul;


int main()
{
    try
    {
        if(!Glew.ready())
            Glew.init();
        return 0;
    }
    catch(const char* exc)
    {
        puts(exc);
    }
    
    return 1;
}
