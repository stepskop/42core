#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat {
private:
	const std::string		_name;
	int									_grade;
public:
	Bureaucrat(void);
	Bureaucrat(std::string &name, int grade);
	Bureaucrat(const Bureaucrat &src);
	~Bureaucrat(void);
	
	Bureaucrat &operator = (const Bureaucrat &src);
	
	class GradeTooHighException : public std::exception {
		virtual const char * what() const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char * what() const throw();
	};

	const std::string &getName() const;
	int								getGrage() const;

	void	incGrade(int val = 1);
	void	decGrade(int val = 1);
};

#endif
