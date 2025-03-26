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
	

	bool LoadAsText(); //�ؽ�Ʈ�� �ε� 
	bool LoadAsBinary(); //���̳ʸ��� �ε�


private:
	std::filesystem::path FilePath;
	std::vector<char> Buffer;
	bool isLoaded;

};

