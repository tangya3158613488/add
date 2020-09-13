#define _CRT_SECURE_NO_WARNINGS 1

/*
��׺ת��׺C++����ʵ��˼·
1.��������������ӵ���׺���ʽ�л�ֱ�����
2.ջ��ʱ�������������ֱ����ջ
3.���������ţ�������ջ
4.���������ţ�ִ�г�ջ�������������׺���ʽ��ֱ����������������
ע�⣺�����Ų��������׺���ʽ
5.��������������������������ȼ����ڻ���ڸ��������ջ��Ԫ�أ�Ȼ�󽫸��������ջ
6.��ջ��ʣ���������ε�����׺���ʽ
*/

#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<string>
#include<cstdio>

using namespace std;

//�������ȼ�(ע��Ĭ�ϲ����������ȼ���ߣ����䲻��Ҫ��ջ����ջ�Ķ��������)
map<char, int> p;

//һЩ��ʼ��********************************************
struct Node{
	double num;//������
	char op;//������
	bool flag;//true��ʾ��������false��ʾ������
};
typedef struct Node node;

stack<node> s;//������ջ
stack<node> s1;//��Ų������ģ�Ϊ�˼����׺���ʽ��ֵ
queue<node> q;//��׺���ʽ����

//******************************************************
//��׺ת��׺����
void change(string str){
	node temp;
	for (int i = 0; i < str.length();){
		if (str[i] == '('){//3.���������ţ�������ջ
			temp.flag = false;
			temp.op = str[i];
			s.push(temp);
			i++;
		}
		else if (str[i] == ')'){//4.���������ţ�ִ�г�ջ�������������׺���ʽ��ֱ����������������
			while (!s.empty() && s.top().op != '('){
				q.push(s.top());
				s.pop();
			}
			s.pop();//����������
			i++;
		}
		else if (str[i] >= '0'&&str[i] <= '9'){
			//���������
			temp.flag = true;
			temp.num = str[i] - '0';
			i++;//����һλ,��Ϊ���ֲ�һ���Ǹ�λ��
			while (i < str.length() && str[i] >= '0'&&str[i] <= '9'){
				temp.num = temp.num * 10 + (str[i] - '0');
				i++;
			}
			q.push(temp);//�����������׺���ʽ
		}
		else{
			//����ǲ�����
			//5.��������������������������ȼӴ��ڻ���ڸ��������ջ��Ԫ�أ�Ȼ�󽫸��������ջ
			temp.flag = false;
			while (!s.empty() && p[s.top().op] >= p[str[i]]){
				q.push(s.top());
				s.pop();
			}
			temp.op = str[i];
			s.push(temp);
			i++;
		}
	}
	//6.��ջ��ʣ���������ε�����׺���ʽ
	while (!s.empty()){
		q.push(s.top());
		s.pop();
	}
}

//*************************************************************
//��׺���ʽ�ļ���
/*
������ɨ���׺���ʽ
1�����ǲ���������ѹջ��
2�����ǲ���������������������������
3��ջ����ֵ��Ϊ������
ע���ȵ������ǵ�һ���������󵯳����ǵڶ�������
*/
double  calculate(){
	double num_a, num_b;//������a,b
	node cur, temp;
	while (!q.empty()){//��׺���зǿ�
		cur = q.front();//��¼����Ԫ��
		q.pop();
		if (cur.flag == true){//�ǲ���������ջ
			s1.push(cur);
		}
		else{//�ǲ�����������
			num_b = s1.top().num;
			s1.pop();//�����ڶ�������
			num_a = s1.top().num;
			s1.pop();//������һ������
			temp.flag = true;
			if (cur.op == '+'){
				temp.num = num_a + num_b;
			}
			else if (cur.op == '-'){
				temp.num = num_a - num_b;

			}
			else if (cur.op == '*'){
				temp.num = num_a * num_b;
			}
			else{
				temp.num = num_a / num_b;
			}
			s1.push(temp);//�Ѽ����Ľ���ٴ�ѹջ
		}
	}
	return s1.top().num;

}
//*************************************************************


int main()
{
	string str;
	p['+'] = p['-'] = 1;//ͨ��hashmap��ֵ��������������ȼ�
	p['*'] = p['/'] = 2;
	cin >> str;
	change(str);

	double answer = calculate();
	cout << answer << endl;
	return 0;
}
