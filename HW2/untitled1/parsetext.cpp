#include "parsetext.h"

ParseText::ParseText(QString txt)
{
    str = txt;
    parse();
}

double ParseText::parse() {
    double value = 0;
    quint32 index = 0;
    value = term(str, index);
    while(1){
        if (str.at(index)=="=") return value;
        else if(str.at(index)=="+") { value += term(str, ++index);}
        else if(str.at(index)=="-") { value -= term(str, ++index);}
        else { return 0; }
    }

}

double ParseText::term (QString str, quint32& index){
    double value = 0;

    value = number(str, index);
    while(1){
        if(str.at(index)=="*") { value *= number(str, ++index);}
        else if(str.at(index)=="/") { value /= number(str, ++index);}
        else { break; }
    }
    return value;
}

double ParseText::number(QString str, quint32& index){
    double value =0;
    if (!(str.at(index).isDigit())){ return 0;}
    while(str.at(index).isDigit()){
        value = 10 * value + (str.at(index++).unicode() - '0');
    }
    if(str.at(index)!='.') return value;
    double factor = 1.0;
    while(str.at(++index).isDigit()){
        factor *=0.1;
        value = value + (str.at(index).unicode() - '0') * factor;
    }
    return value;
}

