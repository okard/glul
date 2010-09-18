
#include <cstdio>
#include <glul/Glew>

using namespace glul;


int main()
{
    if(!Glew.ready())
        Glew.init();
    
    return 1;
}
