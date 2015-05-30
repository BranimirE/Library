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
//o mantenerlo pero no adicionar dentro (sobre, dentro)
vector<Rect> obtenerbordes(Rect abajo, Rect encima) {
  Rect inter = interseccion(abajo, encima);
  vector<Rect> ans;
  if (inter.area == 0) {//No hay interseccion, No cubre nada
    ans.push_back(abajo);//'abajo' se queda igual
    return ans;
  }
  Rect arr(inter.x1,inter.y2,inter.x2, abajo.y2);
  Rect aba(inter.x1, abajo.y1,inter.x2,inter.y1);
  Rect izq(abajo.x1,abajo.y1,inter.x1,abajo.y2);
  Rect der(inter.x2,abajo.y1,abajo.x2,abajo.y2);  
  if (arr.getArea())ans.push_back(arr);
  if (aba.getArea())ans.push_back(aba);
  if (izq.getArea())ans.push_back(izq);
  if (der.getArea())ans.push_back(der);
  return ans;
}
