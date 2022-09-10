#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int idVenda = 1;
int tamV = 0;
using namespace std;

//Classe Produtos com todos os atributos comuns a todos os itens
class Produto {
    //atributos
    protected:
        int unidade;
        int id;
        string nome;
        string tipo;
        float preco;

    public:
    //metodos
        Produto(int _unidade, int _id, string _nome, string _tipo, float _preco);

        void setUnidade(int _unidade);
        int getUnidade();

        void setId(int _id);
        int getId();

        void setNome(string _nome);
        string getNome();

        void setTipo(string _tipo);
        string getTipo();

        void setPreco(float _preco);
        float getPreco();

};

//Construtor
Produto::Produto(int _unidade, int _id, string _nome, string _tipo, float _preco) {
    unidade = _unidade;
    id = _id;
    nome = _nome;
    tipo = _tipo;
    preco = _preco;
}

//gets e sets dos atributos
void Produto::setUnidade(int _unidade) {
    this->unidade = _unidade;
}

int Produto::getUnidade() {
    return unidade;
}

void Produto::setId(int _id) {
    this->id = _id;
}

int Produto::getId() {
    return id;
}

void Produto::setNome(string _nome) {
    this->nome = _nome;
}

string Produto::getNome() {
    return nome;
}

void Produto::setTipo(string _tipo) {
    this->tipo = _tipo;
}

string Produto::getTipo() {
    return tipo;
}

void Produto::setPreco(float _preco) {
    this->preco = _preco;
}

float Produto::getPreco() {
    return preco;
}


//Classe filha Armamento
class Armamento : public Produto {
    private:
        int dano;

    public:
    //metodos
        Armamento(int _unidade, int _id, string _nome, string _tipo, float _preco, int _dano);
        void setDano(int _dano);
        int getDano();
};

//Construtor do armamento
Armamento::Armamento(int _unidade, int _id, string _nome, string _tipo, float _preco, int _dano) : Produto(_unidade, _id, _nome, _tipo, _preco) {
    dano = _dano;
}

//get e set de armamentos
void Armamento::setDano(int _dano) {
    this->dano = dano;
}

int Armamento::getDano() {
    return dano;
}


//Classe filha armadura
class Armadura : public Produto {
    private:
        int durabilidade;

    public:
    //metodos
        Armadura(int _unidade, int _id, string _nome, string _tipo, float _preco, int _durabilidade);

        void setDurabilidade(int _durabilidade);
        int getDurabilidade();
};

//Construtor
Armadura::Armadura(int _unidade, int _id, string _nome, string _tipo, float _preco, int _durabilidade) : Produto(_unidade, _id, _nome, _tipo, _preco) {
    durabilidade = _durabilidade;
}

//get e set
void Armadura::setDurabilidade(int _durabilidade) {
    this->durabilidade = _durabilidade;
}

int Armadura::getDurabilidade() {
    return durabilidade;
}


class Consumivel : public Produto {
    private:
        string uso;

    public:
    //metodos
        Consumivel(int _unidade, int _id, string _nome, string _tipo, float _preco, string _uso);

        void setUSo(string _uso);
        string getUso();
};

Consumivel::Consumivel(int _unidade, int _id, string _nome, string _tipo, float _preco, string _uso) : Produto(_unidade, _id, _nome, _tipo, _preco) {
    uso = _uso;
}

void Consumivel::setUSo(string _uso) {
    this->uso = _uso;
}

string Consumivel::getUso() {
    return uso;
}

class Venda: public Produto {

    private:
        int idV;
        int quantVenda;
        float custoFinal;

    public:
        Venda(int _id, int _idV, string _nome, int _quantVenda, float _preco, float _precoFinal, string _tipo, int _unidade);

        void setIdV(int _idV);
        int getIdV();

        void setQuantvenda(int _quantVenda);
        int getQuantVenda();

        void setCustoFinal(float _custoFinal);
        float getCustoFinal();

};

Venda::Venda(int _id, int _idV, string _nome, int _quantVenda, float _preco, float _precoFinal, string _tipo, int _unidade) : Produto(_unidade, _id, _nome, _tipo, _preco) {

    idV = _idV;
    quantVenda = _quantVenda;
    custoFinal = _precoFinal;

}

void Venda:: setIdV(int _idv) {
    this->idV = _idv;
}

int Venda:: getIdV() {
    return idV;
}

void Venda:: setQuantvenda(int _quant) {
    this->quantVenda = _quant;
}

int Venda:: getQuantVenda() {
    return quantVenda;
}

void Venda:: setCustoFinal(float _custo) {
    this->custoFinal = _custo;
}

float Venda:: getCustoFinal() {
    return custoFinal;
}

//-------------------funcoes-------------------


void criarArm(vector<Armamento>& obj){

    int id, dano, unidade;
    string nome, tipo;
    float preco;


    cout << "Quantas unidades voce deseja cadastrar? ";
    cin >> unidade;
    cout << "ID do produto: ";
    cin >> id;
    fflush(stdin);
    cout << "Nome do item: ";
    getline(cin,nome);
    fflush(stdin);
    cout << "Tipo do item: ";
    cin >> tipo;
    cout << "Preco do item: ";
    cin >> preco;
    cout << "Dano do item: ";
    cin >> dano;

    Armamento novoArm(unidade,id,nome,tipo,preco,dano);
    obj.push_back(novoArm);
    
}

void criarArmadura(vector<Armadura>& obj) {

    int id, durabilidade, unidade;
    string nome, tipo;
    float preco;

    cout << "Quantas unidades voce deseja cadastrar? ";
    cin >> unidade;
    cout << "ID do produto: ";
    cin >> id;
    fflush(stdin);
    cout << "Nome do item: ";
    getline(cin,nome);
    fflush(stdin);
    cout << "Tipo do item: ";
    cin >> tipo;
    cout << "Preco do item: ";
    cin >> preco;
    cout << "Durabilidade do item: ";
    cin >> durabilidade;

    Armadura novaArmadura(unidade,id,nome,tipo,preco,durabilidade);
    obj.push_back(novaArmadura);

}

void criarCons(vector<Consumivel>& obj) {

    int id, unidade;
    string nome, tipo, uso;
    float preco;

    cout << "Quantas unidades voce deseja cadastrar? ";
    cin >> unidade;
    cout << "ID do produto: ";
    cin >> id;
    fflush(stdin);
    cout << "Nome do item: ";
    getline(cin,nome);
    fflush(stdin);
    cout << "Tipo do item: ";
    cin >> tipo;
    cout << "Preco do item: ";
    cin >> preco;
    cout << "Uso do item: ";
    cin >> uso;

    Consumivel novoCons(unidade,id,nome,tipo,preco,uso);
    obj.push_back(novoCons);

}

void exportarArqEst(vector<Armamento>& obj, vector<Armadura>& obj2, vector<Consumivel>& obj3) {

    ofstream arq("estoque.txt");

    //gravando os Armamentos
    arq << "Armamentos" << endl;
    for(int i=0 ; i<obj.size(); i++) {
        arq << obj[i].getUnidade() << " ";
        arq << obj[i].getId() << " ";
        arq << obj[i].getNome() << " ";
        arq << obj[i].getTipo() << " ";
        arq << obj[i].getPreco() << " ";
        arq << obj[i].getDano() << endl;
    }

    arq << "\n\n";

    //gravando as armaduras
    arq << "Armaduras" << endl;
    for(int i=0 ; i<obj2.size(); i++) {
        arq << obj2[i].getUnidade() << " ";
        arq << obj2[i].getId() << " ";
        arq << obj2[i].getNome() << " ";
        arq << obj2[i].getTipo() << " ";
        arq << obj2[i].getPreco() << " ";
        arq << obj2[i].getDurabilidade() << endl;
    }

    arq << "\n\n";

    //gravando os consumiveis
    arq << "Consumiveis" << endl;
    for(int i=0 ; i<obj3.size(); i++) {
        arq << obj3[i].getUnidade() << " ";
        arq << obj3[i].getId() << " ";
        arq << obj3[i].getNome() << " ";
        arq << obj3[i].getTipo() << " ";
        arq << obj3[i].getPreco() << " ";
        arq << obj3[i].getUso() << endl;
    }

    arq.close();

}

void expLogV(vector<Venda>& venda) {

    ofstream arqV("vendas.txt");

    arqV << "Vendas: " << endl;

    for(int i=0; i<venda.size(); i++) {

        arqV << venda[i].getIdV() << " ";
        arqV << venda[i].getId() << " ";
        arqV << venda[i].getNome() << " ";
        arqV << venda[i].getQuantVenda() << " ";
        arqV << venda[i].getPreco() << " ";
        arqV << venda[i].getCustoFinal() << " ";
        arqV << "\n";
    }

    arqV.close();

}

void addVenda(vector<Venda>& venda, int p, vector<Armamento>& obj, int unidades, float valor, vector<Armadura>& obj2, vector<Consumivel>& obj3, int op) {

    if(op==1) {

        Venda novaV (obj[p].getId(), idVenda, obj[p].getNome(), unidades, obj[p].getPreco(), valor, obj[p].getTipo() , unidades);
        venda.push_back(novaV);

        cout << "\nLog de Vendas\n\n";
        cout << "ID da venda: " << venda[tamV].getIdV() << endl;
        cout << "ID do produto: " << venda[tamV].getId() << endl;
        cout << "Nome do item: " << venda[tamV].getNome() << endl;
        cout << "Quantidade de itens vendidos: " << venda[tamV].getUnidade() << endl;
        cout << "Custo por item sem desconto: " << venda[tamV].getPreco() << endl;
        cout << "Custo final: " << venda[tamV].getCustoFinal() << endl;

    } else if(op==2) {

        Venda novaV (obj2[p].getId(), idVenda, obj2[p].getNome(), unidades, obj2[p].getPreco(), valor, obj2[p].getTipo() , unidades);
        venda.push_back(novaV);

        cout << "\nLog de Vendas\n\n";
        cout << "ID da venda: " << idVenda << endl;
        cout << "ID do produto: " << venda[tamV].getId() << endl;
        cout << "Nome do item: " << venda[tamV].getNome() << endl;
        cout << "Quantidade de itens vendidos: " << unidades << endl;
        cout << "Custo por item sem desconto: " << venda[tamV].getPreco() << endl;
        cout << "Custo final: " << valor << endl;

    } else if(op==3) {

        Venda novaV (obj3[p].getId(), idVenda, obj3[p].getNome(), unidades, obj3[p].getPreco(), valor, obj3[p].getTipo() , unidades);
        venda.push_back(novaV);

        cout << "\nLog de Vendas\n\n";
        cout << "ID da venda: " << idVenda << endl;
        cout << "ID do produto: " << venda[tamV].getId() << endl;
        cout << "Nome do item: " << venda[tamV].getNome() << endl;
        cout << "Quantidade de itens vendidos: " << unidades << endl;
        cout << "Custo por item sem desconto: " << venda[tamV].getPreco() << endl;
        cout << "Custo final: " << valor << endl;

    }

    tamV++;
    idVenda++;

}

int teladeConf(int i, int unidade, vector<Armamento>& obj, vector<Venda>& venda, vector<Armadura>& obj2, vector<Consumivel>& obj3, int op){

    float valorNormalTotal, valorD;
    float desconto, descontoP;
    int primos, opcao;
    int tam=0;


    cout << "\nTela de confirmacao\n\n";

    if(op==1) {
        cout << "Custo da unidade: " << obj[i].getPreco() << endl;
        valorNormalTotal = unidade * obj[i].getPreco();
    } else if(op==2) {
        cout << "Custo da unidade: " << obj2[i].getPreco() << endl;
        valorNormalTotal = unidade * obj2[i].getPreco();
    } else if(op==3) {
        cout << "Custo da unidade: " << obj3[i].getPreco() << endl;
        valorNormalTotal = unidade * obj3[i].getPreco();
    }

    cout << "Valor total sem desconto: " << valorNormalTotal <<endl;

    for(int j=0; j<=unidade;j++) {
        primos=0;
        for(int n=1; n<=j; n++) {
            if(j%n==0) {
                primos++;
            }
        }
    }

    descontoP = primos * 2;
    desconto = descontoP/100;
    desconto = desconto*valorNormalTotal;


    cout << "O desconto em PO: " <<desconto << endl;
    cout << "O desconto em %: "<<descontoP << "%" << endl;

    valorD = valorNormalTotal - desconto;
    cout << "O valor total com desconto: " << valorD << endl;


    cout << "\nDeseja continuar a venda?\n1 - SIM\n2 - NAO\n";
    cin >> opcao;

    if(opcao==1) {
        addVenda(venda, i, obj, unidade, valorD, obj2, obj3, op);
    }

    return opcao;

}


void listaArmamentos(vector<Armamento>& obj) {

    int tam = obj.size();

    cout << "\nLista de Armamentos: \n";
    cout << "Unidade        ID           Nome                Tipo                 Preco           Dano\n";
    cout << "-----------------------------------------------------------------------------------------------\n";
    for( int i=0; i<tam; i++) {
        cout << obj[i].getUnidade();
        cout <<"       ||       " << obj[i].getId(); 
        cout << "     ||     " << obj[i].getNome();
        cout<< "     ||     " << obj[i].getTipo();
        cout << "     ||     " << obj[i].getPreco();
        cout << " PO     ||     " << obj[i].getDano() << endl;
    }
}

void listaArmaduras(vector<Armadura>& obj) {

        int tam = obj.size();

    cout << "\nLista de Armaduras: \n";
    cout << "Unidade        ID               Nome                 Tipo                 Preco        Durabilidade\n";
    cout << "---------------------------------------------------------------------------------------------------\n";
    for( int i=0; i<tam; i++) {
        cout << obj[i].getUnidade();
        cout <<"     ||       " << obj[i].getId(); 
        cout << "     ||     " << obj[i].getNome();
        cout<< "     ||     " << obj[i].getTipo();
        cout << "     ||     " << obj[i].getPreco();
        cout << " PO     ||     " << obj[i].getDurabilidade() << endl;
    }

}

void listaCons(vector<Consumivel>& obj) {

        int tam = obj.size();

    cout << "\nLista de Consumiveis: \n";
    cout << "Unidade       ID           Nome             Tipo             Preco            Uso\n";
    cout << "------------------------------------------------------------------------------------------\n";
    for( int i=0; i<tam; i++) {
        cout << obj[i].getUnidade();
        cout <<"       ||     " << obj[i].getId(); 
        cout << "    ||     " << obj[i].getNome();
        cout<< "     ||     " << obj[i].getTipo();
        cout << "     ||     " << obj[i].getPreco();
        cout << " PO     ||     " << obj[i].getUso() << endl;
    }

}

void visLog(vector<Venda>& obj) {

    cout << "\nLog de Vendas" <<endl;
    for(int i=0; i<obj.size(); i++) {
        cout << "\nVenda " << (i+1) <<endl;
        cout << "ID venda: "<< obj[i].getIdV() << endl;
        cout <<"ID produto: " << obj[i].getId() << endl;
        cout <<"Nome: " << obj[i].getNome() << endl;
        cout <<"Numero de itens vendidos: " << obj[i].getQuantVenda() << endl;
        cout <<"Custo por item: " << obj[i].getPreco() << endl;
        cout <<"Custo Final com desconto: " << obj[i].getCustoFinal() << endl;
    }

}

void menuInicial() {
    cout << "\nO que deseja ver?\n1 - Estoque\n2 - Vendas\n3 - Finalizar programa\n" << endl;
}

void menuEstoque() {

    cout << "\n1 - Cadastrar item" << endl;
    cout << "2 - Remover item" <<endl;
    cout <<"3 - Adicionar unidade" <<endl;
    cout <<"4 - Listar o estoque" <<endl;
    cout <<"5 - Exportar estoque para arquivo txt\n" <<endl;

}

void menuItens() {

    cout << "\n1 - Armamento" << endl;
    cout << "2 - Armadura" <<endl;
    cout <<"3 - Consumivel\n" <<endl;
    
}

void menuVenda() {

    cout <<"1 - Realizar venda" <<endl;
    cout <<"2 - Visualizar log de vendas" <<endl;
    cout <<"3 - Exportar vendas para arquivo txt"<<endl;

}



int main() {

    int opcaoInicial, opcaoEstoque, opcaoCadItem, opcaoExcluir, opcaoUnidade, opcaoV;
    int codigo, idUnid, unidade, opcaoVenda, codigoVenda, unidadeVendas;
    int custoU, valorN, desconto, descontoP, valorDes;
    int acum=0;
    int novaUnidade;
    int tamArmamento = 1;
    int tamArmadura = 1;
    int tamCons = 1;

    //Inicializando os vetores
    vector<Armamento> prodArmamento;
    vector<Armadura> prodArmadura;
    vector<Consumivel> prodCons;
    vector<Venda>logVendas;


    //iniciando um tipo de cada já no estoque
    //--Armamento
    Armamento novoArm(1,1,"Fuzil", "Arma de fogo", 120, 90);
    prodArmamento.push_back(novoArm);

    //--Armadura
    Armadura novaArmadura(1, 1, "Corsolete de couro", "Leve", 300, 50);
    prodArmadura.push_back(novaArmadura);

    //--Consumivel
    Consumivel novoCons(1, 1, "Cereal", "Leve", 10, "Energia");
    prodCons.push_back(novoCons);

    menuInicial();
    while(cin >> opcaoInicial, opcaoInicial!=3) {

        while(opcaoInicial <1 || opcaoInicial >3) {
            cout << "Opcao invalida!\nEntre com outra opcao: ";
            cin >> opcaoInicial;
        }
        
        //OPCAO DE ESTOQUE
        if(opcaoInicial==1) {
            
            //menu do estoque
            menuEstoque();
            cin >> opcaoEstoque;

            switch(opcaoEstoque) {
                //cadastro
                case 1:
                    cout << "\nQue item deseja cadastrar?" <<endl;
                    menuItens();
                    cin >> opcaoCadItem;

                    while(opcaoCadItem <1 || opcaoCadItem >3) {
                        cout << "Opcao invalida!\nEntre com outra opcao: ";
                        cin >> opcaoCadItem;
                    }

                    //Cadastra um armamento
                    if(opcaoCadItem == 1) {
                        
                        criarArm(prodArmamento);

                    } 
                    //Cadastra uma armadura
                    else if(opcaoCadItem == 2) {

                        criarArmadura(prodArmadura);

                    }
        
                    else if(opcaoCadItem == 3) {

                        criarCons(prodCons);

                    }
                break;

                case 2:
                    cout << "Qual item deseja excluir?" <<endl;
                    menuItens();
                    cin >> opcaoExcluir;

                    while(opcaoExcluir <1 || opcaoExcluir >3) {
                        cout << "Opcao invalida!\nEntre com outra opcao: ";
                        cin >> opcaoExcluir;
                    }

                    //exclui um armamento
                    if(opcaoExcluir == 1) {
                        
                        if(prodArmamento.size() == 0) {
                            cout << "\nLista vazia, nao tem elementos para excluir!" <<endl;
                            break;
                        }

                        listaArmamentos(prodArmamento);
                        cout <<"\nDigite o ID do item que deseja excluir" <<endl;
                        cin >> codigo;

                        for(int i=0; i<prodArmamento.size(); i++) {
                            if(prodArmamento[i].getId()==codigo) {
                                prodArmamento.erase(prodArmamento.begin()+i);
                                break;
                            }
                        }
                        listaArmamentos(prodArmamento);

                    }
                    //exclui uma armadura
                    else if(opcaoExcluir == 2) {

                        if(prodArmadura.size() == 0) {
                            cout << "\nLista vazia, nao tem elementos para excluir!" <<endl;
                            break;
                        }

                        listaArmaduras(prodArmadura);
                        cout <<"\nDigite o ID do item que deseja excluir" <<endl;
                        cin >> codigo;

                        for(int i=0; i<prodArmadura.size(); i++) {
                            if(prodArmadura[i].getId()==codigo) {
                                prodArmadura.erase(prodArmadura.begin()+i);
                                break;
                            }
                        }
                        listaArmaduras(prodArmadura);

                    } 
                    //Excluir um consumível
                    else if(opcaoExcluir==3) {
                        
                        if(prodCons.size() == 0) {
                            cout << "\nLista vazia, nao tem elementos para excluir!" <<endl;
                            break;
                        }

                        listaCons(prodCons);
                        cout <<"\nDigite o ID do item que deseja excluir" <<endl;
                        cin >> codigo;

                        for(int i=0; i<prodCons.size(); i++) {
                            if(prodCons[i].getId()==codigo) {
                                prodCons.erase(prodCons.begin()+i);
                                break;
                            }
                        }
                        listaCons(prodCons);

                    }

                break;

                //Para adicionar unidades nos itens
                case 3:
                    
                    cout << "Qual item deseja adicionar uma unidade?" <<endl;
                    menuItens();
                    cin >> opcaoUnidade;

                    while(opcaoUnidade <1 || opcaoUnidade >3) {
                        cout << "Opcao invalida!\nEntre com outra opcao: ";
                        cin >> opcaoUnidade;
                    }

                    //adiciona unidade no armamento
                    if(opcaoUnidade==1) {
                        listaArmamentos(prodArmamento);
                        cout << "\nDigite o ID do produto que deseja alterar a unidade: ";
                        cin >> idUnid;

                        for(int i=0; i<prodArmamento.size(); i++) {
                            if(prodArmamento[i].getId()==idUnid) {
                                cout <<"Para quantas unidades deseja aumentar? ";
                                cin >> unidade;
                                prodArmamento[i].setUnidade(unidade);
                                break;
                            }
                        }
                        listaArmamentos(prodArmamento);

                    //adiciona unidades em armaduras
                    } else if(opcaoUnidade==2) {
                        
                        listaArmaduras(prodArmadura);
                        cout << "\nDigite o ID do produto que deseja alterar a unidade: ";
                        cin >> idUnid;

                        for(int i=0; i<prodArmadura.size(); i++) {
                            if(prodArmadura[i].getId()==idUnid) {
                                cout <<"Para quantas unidades deseja aumentar? ";
                                cin >> unidade;
                                prodArmadura[i].setUnidade(unidade);
                                break;
                            }
                        }
                        listaArmaduras(prodArmadura);

                    } else if(opcaoUnidade==3) {

                        listaCons(prodCons);
                        cout << "\nDigite o ID do produto que deseja alterar a unidade: ";
                        cin >> idUnid;

                        for(int i=0; i<prodCons.size(); i++) {
                            if(prodCons[i].getId()==idUnid) {
                                cout <<"Para quantas unidades deseja aumentar? ";
                                cin >> unidade;
                                prodCons[i].setUnidade(unidade);
                                break;
                            }
                        }
                        listaCons(prodCons);
                    }

                break;

                case 4:
                    cout << "Listagem do estoque: " <<endl;
                    listaArmamentos(prodArmamento);
                    listaArmaduras(prodArmadura);
                    listaCons(prodCons);
                break;

                case 5:
                    exportarArqEst(prodArmamento, prodArmadura, prodCons);
                break;

                default:
                    cout << "Opcao invalida"<<endl;
            }



        //Tela de Vendas
        } else if(opcaoInicial == 2) {

            cout << "O que deseja realizar?" << endl;
            menuVenda();
            cin >> opcaoV;

            switch(opcaoV) {

                case 1:
                    listaArmamentos(prodArmamento);
                    listaArmaduras(prodArmadura);
                    listaCons(prodCons);
                    
                    cout<<"\nQual item deseja vender? ";
                    menuItens();
                    cin >> opcaoVenda;

                    while(opcaoVenda <1 || opcaoVenda >3) {
                        cout << "Opcao invalida!\nEntre com outra opcao: ";
                        cin >> opcaoVenda;
                    }

                    //venda de um armamento
                    if(opcaoVenda==1) {
                        
                        int op;
                        int conf;
                        int acum=0;

                        listaArmamentos(prodArmamento);
                        cout << "Qual o ID do produto que deseja vender? ";
                        cin >> codigoVenda;
                        cout << "Quantas unidades? ";
                        cin >> unidadeVendas;
                        
                        for(int i=0; i<prodArmamento.size(); i++) {
                            
                            if(prodArmamento[i].getId()==codigoVenda) {
                                acum++;
                                conf = teladeConf(i, unidadeVendas, prodArmamento, logVendas, prodArmadura, prodCons, opcaoVenda);

                                if(conf==0) {
                                    break;
                                }

                                novaUnidade = prodArmamento[i].getUnidade() - unidadeVendas;

                                if(novaUnidade >=0) {
                                    prodArmamento[i].setUnidade(novaUnidade);
                                    op = i;
                                    
                                    break;
                                } else {
                                    cout<<"\nTamanho disponivel de unidades excedido!" << endl;
                                    break;
                                }

                            } 
                        }
                        
                        if(acum==0) {
                            cout<< "\nID nao encontrado!!" <<endl;
                        }

                        //apagando do estoque caso reste 0 unidades
                        if(novaUnidade==0) {
                            prodArmamento.erase(prodArmamento.begin() + op);
                        }
            
                    }

                    //Venda de uma armadura
                    else if(opcaoVenda==2) {

                        int op;
                        int conf;
                        int acum = 0;

                        listaArmaduras(prodArmadura);
                        cout << "Qual o ID do produto que deseja vender? ";
                        cin >> codigoVenda;
                        cout << "Quantas unidades? ";
                        cin >> unidadeVendas;
                        
                        for(int i=0; i<prodArmadura.size(); i++) {
                            
                            if(prodArmadura[i].getId()==codigoVenda) {
                                acum++;
                                conf = teladeConf(i, unidadeVendas, prodArmamento, logVendas, prodArmadura, prodCons, opcaoVenda);

                                if(conf==0) {
                                    break;
                                }

                                novaUnidade = prodArmadura[i].getUnidade() - unidadeVendas;

                                if(novaUnidade >=0) {
                                    //atualiza o estoque com o novo numero de unidades disponiveis
                                    prodArmadura[i].setUnidade(novaUnidade);
                                    op = i;
                                    
                                    break;
                                } else {
                                    cout<<"\nTamanho disponivel de unidades excedido!" << endl;
                                    break;
                                }

                            } 
                        }
                        
                        //Caso o id não for encontrado
                        if(acum==0) {
                            cout<< "\nID nao encontrado!!" <<endl;
                        }

                        //apagando do estoque caso reste 0 unidades
                        if(novaUnidade==0) {
                            prodArmadura.erase(prodArmadura.begin() + op);
                        }

                    }

                    //Vende um consumivel
                    else if(opcaoVenda==3) {
                        
                        int op;
                        int conf;
                        int acum=0;

                        listaCons(prodCons);
                        cout << "Qual o ID do produto que deseja vender? ";
                        cin >> codigoVenda;
                        cout << "Quantas unidades? ";
                        cin >> unidadeVendas;
                        
                        for(int i=0; i<prodCons.size(); i++) {
                            
                            if(prodCons[i].getId()==codigoVenda) {
                                acum++;
                                conf = teladeConf(i, unidadeVendas, prodArmamento, logVendas, prodArmadura, prodCons, opcaoVenda);

                                if(conf==0) {
                                    break;
                                }

                                novaUnidade = prodCons[i].getUnidade() - unidadeVendas;

                                if(novaUnidade >=0) {
                                    //atualiza o estoque com o novo numero de unidades disponiveis
                                    prodCons[i].setUnidade(novaUnidade);
                                    op = i;
                                    
                                    break;
                                } else {
                                    cout<<"\nTamanho disponivel de unidades excedido!" << endl;
                                    break;
                                }

                            } 
                        }
                        
                        //Caso o id não for encontrado
                        if(acum==0) {
                            cout<< "\nID nao encontrado!!" <<endl;
                        }

                        //apagando do estoque caso reste 0 unidades
                        if(novaUnidade==0) {
                            prodCons.erase(prodCons.begin() + op);
                        }
                        
                    }
                break;

                case 2:
                    visLog(logVendas);
                break;

                case 3:
                    expLogV(logVendas);
                break;

                default:
                    cout << "Nenhuma opcao valida" <<endl;
            }
        }
        menuInicial();
    }

    return 0;
}