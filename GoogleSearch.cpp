#include <iostream>
#include <sys/stat.h>
void openFirefox(std::string url);
void openEdge(std::string url);
void openChrome(std::string url)
{
    const char *file = "C:/Program Files/Google/Chrome/Application/chrome.exe";
    struct stat sb;
    if (stat(file, &sb) == 0 && !(sb.st_mode & S_IFDIR))
    {
        system( ("start chrome " + url).c_str() );
        
    }
    openFirefox(url);
};

void openFirefox(std::string url)
{

    const char *file = "C:/Program Files/Mozilla Firefox/firefox.exe";
    struct stat sb;
    if (stat(file, &sb) == 0 && !(sb.st_mode & S_IFDIR))
    {
        system( ("start firefox " + url).c_str() );
 
    }
    openEdge(url);
}

void openEdge(std::string url)
{
    const char *file = "C:/Program Files (x86)/Microsoft/Edge/Application/msedge.exe";
    struct stat sb;
    if (stat(file, &sb) == 0 && !(sb.st_mode & S_IFDIR))
    {
        system( ("start msedge " + url).c_str() );

    }
}
int main()
{
    std::string url;
    std::cout << "Enter the url of the website: ";
    std::cin >> (url);
    openChrome(url);
}

