#include "FileLoad.h"
#include <Windows.h>

FileLoad::FileLoad(std::filesystem::path _path)
{
	FilePath = _path;
	isLoaded = false;
}


std::vector<std::string> FileLoad::GetAllImage(std::string_view _Path)
{
	std::filesystem::path path(_Path);
	if (!std::filesystem::exists(path)) 
	{
		MessageBoxA(nullptr, "폴더 경로가 존재하지 않습니다!", "FileLoad 에러", MB_OK | MB_ICONERROR);
		return {};
	}

	ImageFile.clear();

	for (const auto& i : std::filesystem::directory_iterator(path))
	{
		if (i.is_regular_file())
		{
			std::string ext = i.path().extension().string();
			if (ext == ".png" || ext == ".bmp")
			{
				ImageFile.push_back(i.path().string());
			}
		}
	}

	return ImageFile;
}

void FileLoad::SetPath(std::string_view _Path)
{
	FilePath = std::filesystem::path(_Path);
	isLoaded = false;
	Buffer.clear();
}

std::string FileLoad::GetFullPath() const
{
	return FilePath.string(); //stirng으로 변환
	//tostring은 없음
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
		return false; //로드 안됨 
	}

	std::ifstream inFile(FilePath, std::ios::in);
	if (!inFile)
	{
		return false;
	}


	Buffer = std::vector<char>((std::istreambuf_iterator<char>(inFile)), {}); //그 크기만큼 일단
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

	//이건 베껴옴 대신 분석해보자
}


*/