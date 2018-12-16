
<?php

class Abecedario
{
    
    private $letras="ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";
    private $tamanio;

    public function __construct()
    {
        $tamanio=strlen($letras);
    }

    private function posicionDeLetra($entrada)
    {
        $pos=-1;
        for ($i=0; $i < $tamanio; $i++) { 
            if ($letras[i] == $entrada) {
                $pos=i;
                break;
            }
        }
        return $pos;
    }

    public function desplazarLetraEn($caracterEntrada,$desplazamiento)
    {
        $posicionLetraEntrada=posicionDeLetra($caracterEntrada);
        if ($posicionLetraEntrada >= 0) {
            $nuevaPosicion=(($posicionLetraEntrada+$desplazamiento)+$tamanio)%$tamanio;
            return $letras[$nuevaPosicion];
        }
        return $caracterEntrada;
    }
    
}
