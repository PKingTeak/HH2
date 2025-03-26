#pragma once
#include<filesystem>
#include<string>
#include <fstream> //���� ����� ���ؼ� 
class FileLoad
{
	FileLoad();
	FileLoad(std::filesystem::path _path);
	~FileLoad();

	void SetPath(std::string_view _Path);//�ּҰ� �ʿ��ϰ���?
	std::string GetFullPath() const;
	std::string GetFileName() const;
	std::string GetExtension() const;
	std::string GetDirectory() const;

	bool IsExists() const;
	bool IsFile() const;
	bool IsDirectory() const; 
	

	//�ϴ� ��� ������ �����;��Ѵ�. 
	std::vector<std::string> GetAllImage(std::string_view _Path);
	
	inline std::string GetText()const
	{
		return std::string(Buffer.begin(), Buffer.end());
	}

	inline const std::vector<char>& GetBuffer() const
	{

		return Buffer; //�̰� ���� ���ϰ� 
	}

private:
	std::filesystem::path FilePath;
	std::vector<char> Buffer;
	bool isLoaded;

};

