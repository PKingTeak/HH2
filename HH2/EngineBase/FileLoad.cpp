#include "FileLoad.h"
#include <Windows.h>

FileLoad::FileLoad(std::filesystem::path _path)
{
	FilePath = _path;
	isLoaded = false;
}



std::vector<std::string> FileLoad::GetAllImage()
{
	
	if (!std::filesystem::exists(FilePath))
	{
		MessageBoxA(nullptr, "폴더 경로가 존재하지 않습니다!", "FileLoad 에러", MB_OK | MB_ICONERROR);
		return {};
	}

	ImageFile.clear();

	for (const auto& i : std::filesystem::directory_iterator(FilePath))
	{
		if (i.is_regular_file()) //일반 파일인지 확인하는 함수 
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


std::filesystem::path FileLoad::FindFloder(std::string_view _fileName)
{
	FilePath = CurPath();
	while (!FilePath.empty())
	{
		std::filesystem::path target = FilePath / _fileName;

		if (std::filesystem::exists(target) && std::filesystem::is_directory(target))
		{
			//return target; 이건 찾은거고 
			return std::filesystem::canonical(target); // 폴더 안까지 들어가야함 
		}

		FilePath = FilePath.parent_path(); // 한 단계 위로 이동
	}

	throw std::runtime_error("찾는 폴더를 상위 경로에서 발견할 수 없습니다.");
}



void FileLoad::SetPath(std::filesystem::path _Path)
{
	FilePath = _Path;
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
