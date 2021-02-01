#include <windows.h>
#include <string>

class convertUtills
{
public:
/**
 * @author TheDxr
 * @return 
 */
    static void U8toGBK(char u8str[], char gbkstr[])
    {
        int len_wchart;
        wchar_t *unicode_2;
        int len_gbk;
        len_wchart = MultiByteToWideChar(CP_UTF8, 0, u8str, -1, NULL, 0);
        unicode_2 = (wchar_t *)malloc(len_wchart * sizeof(wchar_t));
        MultiByteToWideChar(CP_UTF8, 0, u8str, -1, unicode_2, len_wchart);
        len_gbk = WideCharToMultiByte(CP_ACP, 0, unicode_2, -1, NULL, 0, NULL, NULL);
        WideCharToMultiByte(CP_ACP, 0, unicode_2, -1, gbkstr, len_gbk, NULL, NULL);
        free(unicode_2);
    }
    static std::string UTF8toGBK(std::string utf8){
        char * tc;
        int ssize= utf8.size() + 1;
        char *p=new char[ssize];
        strcpy(p,utf8.c_str());
        U8toGBK(p,tc);
        std::string temp(tc);
        return temp;
    }
};