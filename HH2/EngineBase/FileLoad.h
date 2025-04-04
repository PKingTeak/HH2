#pragma once
#include<filesystem>
#include<string>
#include <fstream> //파일 입출력 위해서 
class FileLoad
{
public:
	FileLoad() = default;
	FileLoad(std::filesystem::path _path);
	~FileLoad() = default;

	void SetPath(std::filesystem::path _Path);//주소가 필요하겠지?
	std::string GetFullPath() const;
	std::string GetFileName() const;
	std::string GetExtension() const;
	std::string GetDirectory() const;

	bool IsExists() const;
	bool IsFile() const;
	bool IsDirectory() const; 
	

	//일단 모든 파일을 가져와야한다. 
	const std::vector<std::string>& GetAllImage();
	
	std::filesystem::path FindFloder(std::string_view _fileName);

	inline std::filesystem::path CurPath()
	{
		return std::filesystem::current_path();
	}

	inline std::filesystem::path MoveParent()
	{
		FilePath.parent_path();
	}
	
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
	std::vector<std::string> ImageFile;
	std::vector<char> Buffer;
	bool isLoaded;

};

