/** \brief Realiza la suma de dos numeros y devuelve el resultado
 *
 * \param x primer operando
 * \param y segundo operando
 * \return resultado de la suma
 *
 */
float realizarSuma (float x, float y)
    {
        return x+y;
    }


/** \brief Realiza la resta de dos numeros y devuelve el resultado
 *
 * \param x primer operando
 * \param y segundo operando
 * \return resultado de la resta
 *
 */
float realizarResta (float x, float y)
    {
        return x-y;
    }


/** \brief Realiza la division de dos numeros y devuelve el resultado
 *
 * \param x primer operando
 * \param y segundo operando
 * \return resultado de la division
 *
 */
float realizarDivision (float x, float y)
    {
        return x/y;
    }


/** \brief Realiza la multiplicacion de dos numeros y devuelve el resultado
 *
 * \param x primer operando
 * \param y segundo operando
 * \return resultado de la multiplicacion
 *
 */
float realizarMultiplicacion (float x, float y)
    {
        return x*y;
    }


/** \brief Realiza el factorial de un numero y devuelve el resultado
 *
 * \param x primer operando
 * \return resultado del factorial
 *
 */
double realizarFactorial (double x)
    {
        double resp;
        if(x==0)
            {
                resp= 1;
            }
        else
            {
                resp=x*realizarFactorial(x-1);
            }
        return(resp);
    }






