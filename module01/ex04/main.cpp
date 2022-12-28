# include <iostream> //cout
# include <fstream> //ifstream //ofstream

void	replace(std::fstream &ifs, std::fstream &ofs, char *s1, char *s2)
{
	std::string line;
	size_t initPos;
	size_t findPos;
    std::string findStr = s1;
    std::string replaceStr = s2;

    while (std::getline(ifs, line))
	{
        if (!findStr.empty())
        {
		    initPos = 0;
            findPos = line.find(findStr, initPos);
		    while (findPos != std::string::npos) //str.find() : if no matches were found, the function returns string::npos
		    {
			    line.erase(findPos, findStr.length());
                line.insert(findPos, replaceStr);
			    initPos = findPos + replaceStr.length();
                findPos = line.find(findStr, initPos);
		    }
        }
        ofs << line << std::endl;
    }
}

int main(int argc, char **argv)
{
    std::string filename;
    std::fstream ifs;
    std::fstream ofs;

	if (argc != 4)
	{
		std::cout << "Usage : ./replace <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	filename = argv[1];
    //ifstream = input stream class to operate on files
	ifs.open(filename, std::ifstream::in); //file open for reading
	if (!ifs.good())
	{
		std::cout << "File unknown" << std::endl;
		return (1);
	}
	if (ifs.get() == EOF)
	{
		std::cout << "File empty" << std::endl;
		return (1);
	}
	ifs.seekg(0, ifs.beg);
	filename += ".replace";
    //ofstream = output stream class to operate on files
	ofs.open(filename, std::ofstream::out); //file open for writing
	if (!ofs.good())
	{
		std::cout << "New file creation failed" << std::endl;
		return (1);
	}	
	replace(ifs, ofs, argv[2], argv[3]);
    ifs.close();
	ofs.close();
	return (0);
}
