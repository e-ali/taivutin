# Taivutin

A Finnish word inflector / verb conjugator.

## How to use?

Only has command line interface for now.

Start it on the command line and write a word (e.g. kissa), a verb (e.g.
olla), or an adverb or an interjection (e.g. ei).

It gives the word in all different inflections (kissa: kissaa, kissat,
kissassa, kissaksa, kissat, kissoja, ...), or the verb in all different
conjugation (olla: olen, olin, olen ollut, olisin, olet, olemme , ...),
or for an adverb, interjection or a word that doesn't inflect,
it prints (ei: sana ei taipua).

## Data
* [Kotus](http://kaino.kotus.fi/sanat/nykysuomi/) wordlist.

## Requirements

* [Xerces-C++ XML Parser](https://xerces.apache.org/xerces-c/) (tested with version 3.1.2)
* A C++ compiler with C++-11 support. (tested with G++ 4.9.2)
* [GNU Make](https://www.gnu.org/software/make/) (tested with version 4.1)
