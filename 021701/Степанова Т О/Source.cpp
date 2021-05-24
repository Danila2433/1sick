#include <iostream> 
#include <fstream>
#include <vector>
using namespace std;

bool test(vector <int>* c, vector<vector<int>>* cycle) {
	int pt = 0;
	for (int i = 0; i < (*cycle).size(); i++) {//��������� �������� ����� �������� ����� 
		int p = 0;
		for (int j = 0; j < (*cycle)[i].size(); j++) //��������� �������� �������
			if (find((*c).begin(), (*c).end(), (*cycle)[i][j]) != (*c).end())//���� ����� ������� � �������������� ����� 
				p++;//���� ����, ���������� ������� 
		if (p == (*c).size())//���� ������� ����� ������� �������� �����, �� ����� ���� ��� ���� 
			return false;
	}
	return true;//����� ��� ���
}

void d(int i, int first, int lenght, vector<pair<int, int>> graph, vector <int>* used, vector <int>* c, vector<vector<int>>* cycle) {
	if ((*used)[graph[i].second - 1] == 0 ) {//���� ��������� �������, � ������� ���������� �����,0
		for (int j = 0; j < graph.size(); j++) {
			if (graph[j].first == graph[i].second) {//������� �����, ������� ������� �� ���� �������
				(*used)[graph[j].first - 1] = 1;//������ ��������� �������, � ������� ���������� �����, �� 1
				(*c).push_back(graph[j].first);//���������� ������ ������� � �������������� ���� 
				d(j, first, lenght, graph, used, c, cycle);//�������� ������� ��� ���������� ����� 
			}
		}
	}
	if ((*used)[graph[i].second - 1] == 1 && (*c).size() == lenght && graph[i].second == first && test(c, cycle))//���� ��������� ������� - 1, ����� ����� ���������, first ��������� � ��������, � ������� ���������� �����, ��� �������� ��������� ��� ���� ������� ������� � ������ ����� ��� ���
		(*cycle).push_back((*c));//���������� ������ ���� � ������ ������ ������� ����� 
	(*used)[graph[i].first- 1] = 0;//������ ��������� �������,�� ������� ������� �����, �� 0
	(*c).pop_back();//������� ������ ������� �� ��������������� ����� 
}

void main() {
	int frst, scnd, lenght, N;
	vector<pair<int, int>> graph;
	vector<vector<int>> cycle;
	fstream List;
	List.open("input7.txt");
	List >> lenght >> N;//�� ������� ����� ������� ������������ ����� ������� �����,����� ���������� ������ � �����
	vector <int> used(N, 0);
	while(List>>frst>>scnd)
		graph.push_back(make_pair(frst, scnd));//���������� �����
	List.close();
	for (int i = 0; i < graph.size(); i++) {//��������� ��� ������� ����� ����� 
		used[graph[i].first - 1] = 1;//������ ��������� �������, �� �������� ������� �����, �� 1
		vector <int> c;
		c.push_back(graph[i].first);//���������� ��� ������� � �������������� ���� 
		d(i,graph[i].first, lenght, graph, &used, &c, &cycle);//�������� �������. � first ���������� ������ ������� 
		used[graph[i].first - 1] = 0;// ������ ��������� ������� �� 0
	}
	ofstream List1;
	List1.open("output.txt");
	if(!cycle.size())
		List1 << "��� ����� ����� �����";
	else {//�����
		for (int i = 0; i < cycle.size(); i++) {
			for (int j = 0; j < cycle[i].size(); j++)
				List1 << cycle[i][j] << " ";
			List1 << "\n";
		}
	}
	List1.close();
	return;
}