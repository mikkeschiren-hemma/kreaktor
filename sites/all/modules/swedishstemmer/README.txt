Drupal swedishstemmer module:
----------------------------
Author - Fredrik Jonsson fredrik at combonet dot se
Requires - Drupal 6
License - GPL (see LICENSE)
Credit - Developed from the dutchstemmer module.


Overview:
--------
This module implements the Swedish stemming algorithm to improve 
Swedish-language searching with the Drupal built-in search.module.

It reduces each word in the index to its basic root or stem so that variations
on a word (e.g. "klok, klokare, klokast" or "klockan, klockans") are
considered equivalent when searching. This generally results in more
relevant results.

Algorithm based on
http://snowball.tartarus.org/algorithms/swedish/stemmer.html.

Installation:
------------
1. Place this module directory in your modules folder (this will
   usually be "sites/all/modules/").
2. Go to Administer -> Site building -> Modules and enable the module.
3. Go to Administer -> Site configuration -> Search settings and click "Re-index site".


Last updated:
------------
$Id: README.txt,v 1.2.2.1 2010/01/04 03:45:32 frjo Exp $