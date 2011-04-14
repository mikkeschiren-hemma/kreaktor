
This module provides an Excel parser for feeds.module.

Requirements
============
- Feeds 1.x
  http://drupal.org/project/feeds
- Token 1.x
  http://drupal.org/project/token
- phpExcelReader
  http://sourceforge.net/projects/phpexcelreader/files/Spreadsheet_Excel_Reader/Interim%20update/phpExcelReader.zip/download
  with slight modification @see phpExcelReader.patch

Installation
============
- Install Feeds, Feeds Admin UI, Token and its dependecnies
- Copy this module to your modules directory
- Place the phpExcelReader in this modules' libraries-folder
- Enable feeds_excel

Now it can be used as Parser in Feeds.

Problems with large files
=========================
There's a bottle neck in batch processing of feeds.module at the moment. This
can cause (large) excel files not getting completely imported. For more
information on this issue visit http://drupal.org/node/712304.

Parser Settings
========
Mapping mode:
  Currently there are two modes:
  * "rows" runs through iterative range row-by-row, so each row is a new dataset
  * "columns" runs through iterative range column-by-column, so each column is a new dataset

Fixed Range:
  a region that holds absolute variables, that can be fetch by [sheet-cell-R-C],
  where R represents the row number and C the column number

Iterative Range:
  This is the region where datasets are processed from, either by row or by
  column.

Header Range:
  This option is currently disabled.

Keys for mapping sources
========================
Keys are processed through token.module, so see the "Legend sources" fieldset
on the mapping settings page.

phpExcelReader
==============
The module needs phpExcelReader from http://sourceforge.net/projects/phpexcelreader/
placed into libraries, so reader.php is located at
sites/all/modules/custom/feeds_excel/libraries/phpExcelReader/Excel/reader.php)

Changes to reader.php:

comment line 31
+ //require_once 'Spreadsheet/Excel/Reader/OLERead.php';
- require_once 'Spreadsheet/Excel/Reader/OLERead.php';

remove '+1' in line 970:
-            $utcValue = round(($utcDays+1) * SPREADSHEET_EXCEL_READER_MSINADAY);
+            $utcValue = round(($utcDays) * SPREADSHEET_EXCEL_READER_MSINADAY);