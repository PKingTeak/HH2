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
		MessageBoxA(nullptr, "���� ��ΰ� �������� �ʽ��ϴ�!", "FileLoad ����", MB_OK | MB_ICONERROR);
		return {};
	}

	ImageFile.clear();

	for (const auto& i : std::filesystem::directory_iterator(FilePath))
	{
		if (i.is_regular_file()) //�Ϲ� �������� Ȯ���ϴ� �Լ� 
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
			//return target; �̰� ã���Ű� 
			return std::filesystem::canonical(target); // ���� �ȱ��� ������ 
		}

		FilePath = FilePath.parent_path(); // �� �ܰ� ���� �̵�
	}

	throw std::runtime_error("ã�� ������ ���� ��ο��� �߰��� �� �����ϴ�.");
}



void FileLoad::SetPath(std::filesystem::path _Path)
{
	FilePath = _Path;
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
