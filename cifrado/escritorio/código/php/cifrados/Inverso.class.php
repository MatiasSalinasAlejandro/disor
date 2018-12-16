<?php

class Inverso  
{
    var $texto;

    public function __construct($entrada)
    {
        $this->texto=$entrada;
    }

    public function invertir()
    {
        return strrev($this->texto);
    }
}
