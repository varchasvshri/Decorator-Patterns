#ifndef chocolate_boiler_hpp
#define chocolate_boiler_hpp

class ChocolateBoiler{
	bool empty;
	bool boiled;
	ChocolateBoiler(){
		empty = true;
		boiled = false;
	}

	static ChocolateBoiler* uniqueInstance;
public:
	static ChocolateBoiler* getInstance(){
		if(uniqueInstance == NULL){
			uniqueInstance = new ChocolateBoiler();
			std::cout<<"New instance of chocolate boiler has been created\n";
		}
		else{
			std::cout<<"instance has already been created\n";
		}
		return uniqueInstance;
	}

	void fill(){
		if(isEmpty()){
			empty=false;
			boiled=true;
		}
		std::cout<<"Filled up\n";
	}

	void drain(){
		if(!isEmpty() && isBoiled()){
			empty = true;
		}
		std::cout<<"drained\n";
	}

	void boil(){
		if(!isEmpty() && !isBoiled()){
			boiled = true;
		}
		std::cout<<"boiled\n";
	}

	bool isEmpty(){
		if(empty) std::cout<<"Container is Empty\n";
		else std::cout<<"Container is full\n";
		return empty;
	}
	bool isBoiled(){
		if(boiled) std::cout<<"mixture is boiled\n";
		else std::cout<<"mixture is not boiled\n";
		return boiled;
	}

};

#endif