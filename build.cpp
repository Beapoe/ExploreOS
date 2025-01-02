#include <fstream>
#include <iostream>
#include <string>

int main(){
	std::ofstream kernel;
	std::ifstream temp;
	char buffer[512];
	kernel.open("kernel.bin",std::ios::out | std::ios::binary);
	struct toCombine{
		std::string name;
		unsigned long offset;
	};
	toCombine toCombines[2]={
		{
			"boot16.bin",
			0
		},
		{
			"boot32.bin",
			0x20000-0x10000
		}
	};


	for(toCombine file:toCombines){
		temp.open(file.name,std::ios::in | std::ios::binary);
		while(1){
			temp.read(buffer,sizeof(buffer));
			if(buffer){
				kernel.write(buffer,sizeof(buffer));
				for(int i=0;i<sizeof(buffer);i++) buffer[i] = '\0';
			}else{
				break;
			}
		}
		temp.close();
		if(file.offset != 0) kernel.seekp(file.offset,std::ios::beg);
	}
	return 0;
}
