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
	

	//일단 모든 파일을 가져와야한다. 
	std::vector<std::string> GetAllImage(std::string_view _Path);
	
	inline std::string GetText()const
	{
		return std::string(Buffer.begin(), Buffer.end());
	}

	inline const std::vector<char>& GetBuffer() const
	{

		return Buffer; //이건 수정 못하게 
	}

private:
	std::filesystem::path FilePath;
	std::vector<char> Buffer;
	bool isLoaded;

};

