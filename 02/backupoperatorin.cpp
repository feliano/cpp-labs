	std::string str;
  	in >> str;

  	std::string str2 ("(");  	
  	std::string str3 (",");
  	std::string str4 (")");

	// find '(' , then find ',' then find ')'
  	std::size_t index1 = str.find(str2);
	std::size_t index2 = str.find(str3);
 	std::size_t index3 = str.find(str4);
 	 
 	// if indices are std::string::npos
 	// '(' - not found, only 'real' is valid option
	if(index1 == std::string::npos){
		std::cout << str << "only 'real' is valid option" << std::endl;
		// try to convert string to double
		try{

			// TODO CHECK IF CHARACTERS ARE NUMBERS
			for(int i = 0; i<str.size();++i){

				if((str[i] > '9' || str[i] < '0') && str[i] != '-'){
					std::cout << "Error: string not numerical" << std::endl;
					throw 1;
					return in;
				}
			}

			double real = std::stod(str);
			c = Complex(real);
			return in;

		}catch (const std::exception& ex){
			std::cout << "Error: " << ex.what() << std::endl;
			throw 2;
			return in;
		}
	}

	// count occurences of '(' in string
	int opening_count = 0;
	for (int i = 0; i<str.size(); ++i){
		if(str[i] == '('){
			opening_count++;
		}
	}

	if(opening_count > 1){
		std::cout << "Error: too many opening parentheses" << std::endl;
		throw 3;
		return in;
	}	

	//count occurences of ',')in string
	// if)',' doesn't exist - given earlier check this violates input form
	// if ',' exists more than once -> violates input form
	int comma_count = 0;
	for (int i = 0; i<str.size(); ++i){
		if(str[i] == ','){
			comma_count++;
		}
	}

	if(comma_count == 0 || comma_count > 1){
		std::cout << "Error: too many commas" << std::endl;
		throw 4;
		return in;
	}

	// comma position must be greater than index of '('
	if(index2 < index1){
		std::cout << "Ill formed complex number: ',' before '('" << std::endl;
		throw 5;
		return in;
	}

	// count occurences of ')' in string
	// if ')' doesn't exist - given earlier check this violates input form
	// if ')' exists more than once -> violates input form
	int closing_count = 0;
	for (int i = 0; i<str.size(); ++i){
		if(str[i] == ')'){
			closing_count++;
		}
	}

	if(closing_count == 0 || closing_count > 1){
		std::cout << "Error: too many closing parentheses" << std::endl;
		throw 6;
		return in;
	}	

	// index for ')' must be greater than ','
	if(index3 < index2){
		std::cout << "Ill formed complex number: ')' before ','" << std::endl;
		throw 7;
		return in;
	}

 	// extract substrings
 	std::string real_str = str.substr(index1 + 1,index2 - index1 -1);
	std::string imag_str = str.substr(index2 + 1,index3 - index2 -1);

	// TODO: go through and check that string only contains numbers.
	for(int i = 0; i<real_str.size(); ++i){
		std::cout << "part: " << real_str[i] << " " << (int) real_str[i] << std::endl;
		if(real_str[i] > '9' || real_str[i] < '0'){
			std::cout << "ERROR: real part is not numerical: " <<  (int) real_str[i] <<std::endl;
			std::cout << "ERROR: real part is not numerical: " <<  real_str <<std::endl;
			throw 8;
			return in;
		}
	}

	for(int i = 0; i<imag_str.size(); ++i){
		if(imag_str[i] > '9'){
			std::cout << "ERROR: imag part is not numerical" << std::endl;
			throw 9;
			return in;
		}
	}


	std::cout << "real: " << real_str << std::endl;
	std::cout << "imag: " << imag_str << std::endl;
	
	double real = 0.0;
	double imag = 0.0;

	try{

		real = std::stod(real_str);
		imag = std::stod(imag_str);

		std::cout << "real: " << real << std::endl;
		std::cout << "imag: " << imag << std::endl;

	}catch(const std::exception& ex){
			std::cout << "Error: " << ex.what() << std::endl;
			throw 10;
			return in;
	}

	c = Complex(real,imag);

	return in;