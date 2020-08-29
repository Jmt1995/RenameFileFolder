#include<iostream>
#include<vector>
#include<io.h>
#include <bits/stdc++.h>
using namespace std;
#define MAX_PATH 80
//string key = "【带你入门 请关注公众号 两猿社】";
//string key = "【带你入门，关注公众号：两猿社】";
//string key = "【带你入门 请关注公众号_两猿圈】";
string key = "【带你入门，关注公众号：两猿社】";

//
void getFiles( string path, vector<string>& files );
void getFiles( string path, vector<string>& files )
{
    //文件句柄
    long   hFile   =   0;
    //文件信息
    struct _finddata_t fileinfo;
    string p;
    if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) !=  -1)
    {
        do
        {
            //如果是目录,迭代之
            //如果不是,加入列表
            if((fileinfo.attrib &  _A_SUBDIR))
            {

                string old = fileinfo.name;
                string str  = fileinfo.name;
                int pos = str.find(key);
                int n = key.size();


                cout<<pos<<"　"<<n<<endl;
                if(pos != -1)
                {
                    str = str.erase(pos, n);
                    cout<<str<<endl;

                string newFullName = p.assign(path).append("\\").append(str);
                string oldFullName = p.assign(path).append("\\").append(old);

                if (!rename(oldFullName.c_str(), newFullName.c_str()))
                {
                    cout << "rename fold success "<< endl;

                //if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
                    getFiles( newFullName, files );

                }
                else
                {
                    cout << "rename fold error "<< endl;
                   // if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
                    getFiles( oldFullName, files );
                }

                }
                else{
                     if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
                    getFiles( p.assign(path).append("\\").append(fileinfo.name), files );
                }
                 cout<<str<<endl;




            }
            else
            {
                files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
                cout<<fileinfo.name<<endl;

                string old = fileinfo.name;
                string str  = fileinfo.name;
                int pos = str.find(key);
                int n = key.size();
                if(str.size() > n)
                {

                cout<<pos<<"　"<<n<<endl;
                if(pos != -1)
                {
                    str = str.erase(pos, n);

                string newFullName = p.assign(path).append("\\").append(str);
                string oldFullName = p.assign(path).append("\\").append(old);

                if (!rename(oldFullName.c_str(), newFullName.c_str()))
                {
                    cout << "rename file success "<< endl;
                }
                else
                {
                    cout << "rename file error "<< endl;
                }
                }
                }
                 cout<<str<<endl;
            }
        }while(_findnext(hFile, &fileinfo)  == 0);
        _findclose(hFile);
    }
}

int main()
{
	vector<string> files;
	char * filePath = "F:\\C++学习";

	////获取该路径下的所有文件
	getFiles(filePath, files);
	char str[30];
	int size = files.size();
	/*for (int i = 0;i < size;i++)
	{
	    cout<<files[i].c_str()<<endl;
	}*/
	return 0;
}
