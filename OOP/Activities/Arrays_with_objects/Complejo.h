//
//  Complejo.h
//  ClaseComplejo
//
//  Created by Yolanda Martinez on 1/30/18.
//  Copyright Â© 2018 com.itesm. All rights reserved.
//

#ifndef Complejo_h
#define Complejo_h

class Complejo{
private:
    int real, imag;
    
public:
    Complejo();
    Complejo(int r, int i);
    
    int getReal() { return real; }
    void setReal(int r) { real = r; }
    int getImag() {return imag; }
    void setImag(int i) { imag = i; }
    void muestra();
    Complejo suma(Complejo c2);
    Complejo resta(Complejo c2);
    Complejo sumaTodo(complejo c2);
    
};

Complejo::Complejo()
{
    real = 0;
    imag = 0;
}

Complejo::Complejo(int r, int i)
{
    real = r;
    imag = i;
}

void Complejo::muestra() 
{
    cout << "("<< real<<", "<<imag<<")";
}

Complejo Complejo::suma(Complejo c2) 
{
    Complejo resp;
    
    resp.real = real + c2.real;
    resp.imag = imag + c2.imag;
    
    return resp;
}

Complejo Complejo::resta(Complejo c2)
{
    Complejo resp;

    resp.real = real - c2.real;
    resp.imag = imag - c2.imag;

    return resp;
}

Complejo Complejo::sumaTodo(Complejo c2)
{
    Complejo resp;

    resp.real += real + c2.real;
    resp.imag += imag + c2.imag;

    return resp;
}

#endif /* Complejo_h */