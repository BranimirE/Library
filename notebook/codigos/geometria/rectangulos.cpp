struct Rect{
  int x1,y1, x2,y2;
  int area;
  Rect(int _x1, int _y1, int _x2, int _y2){
    x1 = _x1;
    y1 = _y1;
    x2 = _x2;
    y2 = _y2;
    getArea();
  }
  int getArea(){
    if(x1>=x2 || y1>=y2)return area = 0;
    return area = (x2-x1)*(y2-y1);
  }
};

Rect interseccion(Rect t, Rect r){
  int x1,y1,x2,y2;
  x1 = max(t.x1,r.x1);
  y1 = max(t.y1,r.y1);
  x2 = min(t.x2,r.x2);
  y2 = min(t.y2,r.y2);
  Rect res(x1,y1,x2,y2);
  return res;
}
/*
--------------------
|    |   arr  |    |  <=== sobre
|    |________|    |
|    |        |    |
|izq | dentro | der| 
|    |________|    |
|    |        |    |
|    |   aba  |    |
--------------------
 */
//Si "dentro" cubre todo "sobre" no olvidar borrar "sobre"
//o mantenerlo pero no adicionar dentro
vector<Rect> obtenerbordes(Rect sobre, Rect dentro) {
  Rect inter = interseccion(sobre, dentro);
  Rect arr(inter.x1,inter.y2,inter.x2, sobre.y2);
  Rect aba(inter.x1, sobre.y1,inter.x2,inter.y1);
  Rect izq(sobre.x1,sobre.y1,inter.x1,sobre.y2);
  Rect der(inter.x2,sobre.y1,sobre.x2,sobre.y2);
  vector<Rect> ans;
  if (arr.getArea())ans.pb(arr);
  if (aba.getArea())ans.pb(aba);
  if (izq.getArea())ans.pb(izq);
  if (der.getArea())ans.pb(der);
  return ans;
}
