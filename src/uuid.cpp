#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.
#include <string>
#include <boost/lexical_cast.hpp>
#include "uuid.h"




using std::string;

/*class Uuid{
	
public:
string generate_uuid(void);
Uuid(){
	}
};*/

string Uuid::generate_uuid(){
    	boost::uuids::uuid uuid = boost::uuids::random_generator()();
	//string s=uuid;	
//	return s;    
const std::string tmp = boost::lexical_cast<std::string>(uuid);
	return tmp;


	//std::cout << uuid << std::endl;
}
/*int main(){
	Uuid* s=new Uuid();
	std::cout<<s->generate_uuid();


}*/

