#include <libxml++/libxml++.h>
#include <libxml++/parsers/textreader.h>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	string chc, nom, v1, v2, name, val;
	string chc1 = "RUB", nom1 ="1", name1 = "Российский Рубль", val1 = "1,0";
    	string chc2 = "RUB", nom2 ="1", name2 = "Российский Рубль", val2 = "1,0";
	string current_value, current_name;
	xmlpp::TextReader reader("xml.xml");

	if (argc > 3) {
		v1 = argv[2];
		v2 = argv[3];
	}
	else
		cin >> v1 >> v2;
	//int count = -2;
	while (reader.read()) //&& count != 0)
	{
		int depth = reader.get_depth();
		
		//if (depth = 2 && (v1 == chc || v2 == chc1))
		//{
		if (depth == 2)
		{
			current_name = (string)reader.get_name();
			if (reader.get_depth() == 3)
				current_value = (string)reader.get_value();
			else
				continue;

			if (current_name == "CharCode")
			{
				reader.read();
				chc = current_value;
			}
			else if (current_name == "Nominal")
			{
				reader.read();
				nom = current_value;
			}
			else if (current_name == "Name")
			{
				reader.read();
				name = current_value;
			}
			else if (current_name == "Value")
			{
				reader.read();
				val = current_value;
				if (v1 == chc)
				{
					val1 = val;
					name1 = name;
					nom1 = nom;
				}
				if (v2 == chc)
				{
					val2 = val;
					name2 = name;
					nom2 = nom;
				}
			}
		}
		

	}
	int k, k1;
	k = val1.find(",");
	k1 = val2.find(",");
	val1.replace(k, 1, ".");
	val2.replace(k1, 1, ".");
	float val11 = stof(val1);
	float val22 = stof(val2);
	float nom11 = stof(nom1);
	float nom22 = stof(nom2);

	if (v1 == "RUB")
	{
		cout << (1/(val22 / nom22)) << endl;
	}
	else if(v2 == "RUB")
	{ 
		cout << (val11 / nom11) << endl;
	}
	else
	{ 
		cout << ((val11 / nom11) / (val22 / nom22)) << endl;
	}

	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << endl;
	}
	
	//cout << val2 << endl;

	return 0;
}
