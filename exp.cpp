#include<bits/stdc++.h>

using namespace std;

float operation(float n1, float n2, char op){
	switch(op){
		case '+':
			return n1 + n2;
			break;
		case '-':
			return n1 - n2;
			break;
		case '*':
			return n1 * n2;
			break;
		case '/':
			return n1 / n2;
			break;
	}
}

int main(void){
	string exp;
	int start = 0, end = -1, op = -1;
	float n1, n2, res;
	
	cout<<"Expression: "<<endl;
	cin>>exp;
	
	for(int i=0; i<exp.size(); ++i){
		if(exp[i] == '+' || exp[i] == '-'){
			if(op == -1) op = i;
			else end = i-1;
		}
		if(i == exp.size() - 1) end = i;
		
		cout<<"exp["<<i<<"]: "<<exp[i]<<" - start: "<<start<<" - op: "<<op<<" - end: "<<end<<endl;	//TODO: remove
		
		if(end != -1){
			string sn1 = exp.substr(start, op-start);	//substring n1
			string sn2 = exp.substr(op+1, end-op);		//substring n2
			n1 = atof(sn1.c_str());						//string to float n1
			n2 = atof(sn2.c_str());						//string to float n2
			res = operation(n1, n2, exp[op]);			//operation
			cout<<"n1: "<<n1<<" - n2: "<<n2<<" - res: "<<res<<endl;									// TODO: remove
		}
	}
}
