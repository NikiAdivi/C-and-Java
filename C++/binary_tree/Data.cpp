#include "Tree.h"

  Data::Data(const int index,char* name):_index(index)
  {
    _name=name;
  }
  char* Data::get_name()
  {
    return _name;
  }
  int Data::get_index()
  {
    return _index;
  }

  ostream& operator<<(ostream& os,const Data& data)
  {
    using namespace std;  //It can be inside class defn also.
    os<<data._index<<" "<<data._name<<"\t";
    return os;
  }
