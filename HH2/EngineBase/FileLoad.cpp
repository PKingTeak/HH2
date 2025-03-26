#include "FileLoad.h"

FileLoad::FileLoad()
{
	FilePath=std::filesystem::current_path();
	isLoaded = false;
}

FileLoad::FileLoad(std::filesystem::path _path)
{
	FilePath = _path;
	isLoaded = false;
}

FileLoad::~FileLoad()
{


}



void FileLoad::SetPath(std::string_view _Path)
{
	FilePath = std::filesystem::path(_Path);
	isLoaded = false;
	Buffer.clear();
}

std::string FileLoad::GetFullPath() const
{
	return FilePath.string(); //stirng���� ��ȯ
	//tostring�� ����
}


std::string FileLoad::GetFileName() const
{
	return FilePath.filename().string();
}

std::string FileLoad::GetExtension() const
{
	return FilePath.extension().string();
}

std::string FileLoad::GetDirectory() const
{
	return FilePath.parent_path().string();
}

bool FileLoad::IsExists() const
{
	return std::filesystem::exists(FilePath);
}

bool FileLoad::IsFile() const
{
	return std::filesystem::is_regular_file(FilePath);
}

bool FileLoad::IsDirectory() const
{
	return std::filesystem::is_directory(FilePath);
}
/*
bool FileLoad::LoadAsText()
{
	if (!IsFile())
	{
		return false; //�ε� �ȵ� 
	}

	std::ifstream inFile(FilePath, std::ios::in);
	if (!inFile)
	{
		return false;
	}


	Buffer = std::vector<char>((std::istreambuf_iterator<char>(inFile)), {}); //�� ũ�⸸ŭ �ϴ�
	inFile.close();
	isLoaded = true;
	return true;



}



bool FileLoad::LoadAsBinary()
{
	if (!IsFile()) return false;

	std::ifstream inFile(FilePath, std::ios::binary | std::ios::ate);
	if (!inFile) return false;

	std::streamsize size = inFile.tellg();
	inFile.seekg(0, std::ios::beg);

	Buffer.resize(size);
	inFile.read(Buffer.data(), size);
	inFile.close();
	isLoaded = true;
	return true;

	//�̰� ������ ��� �м��غ���
}


*/