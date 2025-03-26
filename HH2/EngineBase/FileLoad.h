#pragma once
#include<filesystem>
#include<string>
#include <fstream> //파일 입출력 위해서 
class FileLoad
{
	FileLoad();
	FileLoad(std::filesystem::path _path);
	~FileLoad();

	void SetPath(std::string_view _Path);//주소가 필요하겠지?
	std::string GetFullPath() const;
	std::string GetFileName() const;
	std::string GetExtension() const;
	std::string GetDirectory() const;

	bool IsExists() const;
	bool IsFile() const;
	bool IsDirectory() const; 
	

	bool LoadAsText(); //텍스트로 로드 
	bool LoadAsBinary(); //바이너리로 로드


private:
	std::filesystem::path FilePath;
	std::vector<char> Buffer;
	bool isLoaded;

};

