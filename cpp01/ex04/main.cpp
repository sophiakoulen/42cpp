/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:10:06 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/10 17:16:57 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::cerr;
using std::endl;
using std::strerror;

int main(int argc, char **argv)
{
	/* parsing input */

	if (argc != 4)
	{
		cerr << "usage: ./sed2 filename s1 s2" << endl;
		return (1);
	}

	string	filename(argv[1]);

	string	to_erase(argv[2]);
	if (to_erase.empty())
	{
		cerr<<"error: s1 cannot be empty"<<endl;
		return (1);
	}

	string	to_insert(argv[3]);

	/* open input file */

	std::ifstream	input;
	input.open(filename, std::ifstream::in);
	if (!input.good())
	{
		cerr << filename << ": " <<strerror(errno)<<endl;
		return (1);
	}

	/* open output file */

	std::ofstream	output;
	output.open(filename + ".replace", std::ofstream::out);
	if (!output.good())
	{
		cerr << filename + ".replace: "<<strerror(errno)<<endl;
		return (1);
	}

	/* do string replacement, line by line */

	string	line;
	while (std::getline(input, line))
	{
		size_t	pos = 0;
		while (1)
		{
			pos = line.find(to_erase, pos);
			if (pos == string::npos) //if we didn't find any occurence
				break;
			else
			{
				line.erase(pos, to_erase.length());
				line.insert(pos, to_insert);
				pos += to_insert.length();
			}
		}
		if (!(output<<line<<endl))
		{
			cerr<<"error when writing to output file"<<endl;
			break ;
		}
	}

	/* clear error bits of streams to detect closing errors */

	input.clear();
	output.clear();

	/* close streams */

	input.close();
	if (input.fail())
	{
		cerr<< filename <<": "<<std::strerror(errno)<<endl;
		return (1);
	}

	output.close();
	if (output.fail())
	{
		cerr<< filename + ".replace: "<<std::strerror(errno)<<endl;
		return (1);
	}

	return (0);
}
