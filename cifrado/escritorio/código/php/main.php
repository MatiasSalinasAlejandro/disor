<?php

require "cifrados/Cesar.class.php";
require "cifrados/Inverso.class.php";
require "cifrados/InversoGrupal.class.php";

// Normal autoload
$autoload = __DIR__ . '/../../vendor/autoload.php';

// support for composer require autoload
if (! file_exists($autoload)) {
    $autoload = __DIR__ . '/../../../../autoload.php';
}

require $autoload;
use Gui\Application;
use Gui\Components\Label;
use Gui\Components\InputText;
use Gui\Components\Button;
use Gui\Components\Shape;
use Gui\Components\Window;
use Gui\Components\Checkbox;
use Gui\Components\Radio;
use Gui\Components\Select;
use Gui\Components\TextArea;
use Gui\Components\Option;


$application = new Application([
    'title' => 'CIFRADOS',
    'left' => 30,
    'top' => 40,
    'width' => 1100,
    'height' => 600
]);

$application->on('start',function (){
    new Label([
        'text' => 'Texto plano:',
        'top' => 10,
        'left' => 350,
        'fontSize' => 12,
    ]);

    $textoPlano=(new TextArea())
                ->setTop(40)
                ->setLeft(350)
                ->setFontSize(12)
                ->setWidth(320)
                ->setHeight(100);
    
    $btnCifrar = (new Button())
                ->setLeft(600)
                ->setTop(150)
                ->setWidth(50)
                ->setValue('Cifrar');


    //CESAR
    new Label([
        'text' => 'Cesar',
        'top' => 250,
        'left' => 50,
        'fontSize' => 20,
    ]);

    new Label([
        'text' => 'Desplazamiento:',
        'top' => 300,
        'left' => 50,
        'fontSize' => 12,
    ]);

    $txtDesplazamiento=(new InputText())
                ->setTop(320)
                ->setLeft(50)
                ->setFontSize(12)
                ->setWidth(220);

    // $btnCifrarCesar = (new Button())
    //             ->setLeft(200)
    //             ->setTop(350)
    //             ->setWidth(50)
    //             ->setValue('Cifrar');

    new Label([
        'text' => 'Cifrado:',
        'top' => 400,
        'left' => 50,
        'fontSize' => 12,
    ]);

    $txtCifradoCesar=(new TextArea())
                ->setTop(430)
                ->setLeft(50)
                ->setFontSize(12)
                ->setWidth(280)
                ->setHeight(150);
                  
    // INVERSO
    
    new Label([
        'text' => 'Inverso',
        'top' => 250,
        'left' => 450,
        'fontSize' => 20,
    ]);

    // $btnCifrarInverso = (new Button())
    //             ->setLeft(550)
    //             ->setTop(300)
    //             ->setWidth(50)
    //             ->setValue('Cifrar');

    new Label([
        'text' => 'Inverso:',
        'top' => 400,
        'left' => 400,
        'fontSize' => 12,
    ]);

    $txtCifradoInverso=(new TextArea())
                ->setTop(430)
                ->setLeft(400)
                ->setFontSize(12)
                ->setWidth(280)
                ->setHeight(150);



    // INVERSO GRUPAL
    new Label([
        'text' => 'Inverso Grupal',
        'top' => 250,
        'left' => 750,
        'fontSize' => 20,
    ]);
    
    // $btnCifrarInversoGrupal = (new Button())
    //             ->setLeft(750)
    //             ->setTop(300)
    //             ->setWidth(50)
    //             ->setValue('Cifrar');

    new Label([
        'text' => 'Inverso Grupal:',
        'top' => 400,
        'left' => 750,
        'fontSize' => 12,
    ]);

    $txtCifradoInversoGrupal=(new TextArea())
                        ->setTop(430)
                        ->setLeft(750)
                        ->setFontSize(12)
                        ->setWidth(280)
                        ->setHeight(150);



    



    

    $btnCifrar->on('click',function(){
        $textoSinCifrar=$textoPlano->getValue();        
        $desplazamiento=$txtDesplazamiento->getValue();


    });

});

$application->run();