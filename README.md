# Unit Conversion Tool
This unit conversion tool is able to display all present units, one
being the SI unit of one group and updates its results on edit.

SxWConvert Howto
17. August 2007, Neue Einheitenumrechnung hinzufuegen anhand des Beispiels des
    Trägheitsmoments: From To Multiply By: pound square foot kilogram square
meter 0.042 140 11 Diese Anleitung basiert auf SxWConvert 0.66 [dev] mit Qt
4.3.1 Zunächst ist die Datei mainwindow_convert.ui aus dem Unterverzeichnis ui
des SxWConvert Basiverzeichnisses im Designer zu öffnen: Durch Rechtsklick auf
das Tab-Control ein neuen Tab hinzufuegen: Im Property Editor den Tab benennen
und ggf eine Beschreibung eingeben: Ziehen Sie aus der Tool-Palette die Labels
und Line-Edits in das neue Tab. Benennen Sie die Line-Edit Felder nach
folgendem Schema: txt_{Gruppenname}_{Einheitenname} In diesem Beispiel benutzen
wir: txt_mom_kgmsquared fuer die SI-Einheit und txt_mom_poundsquarefoot Das
"mom" ist in diesem Fall der Gruppenname für "Momentum of Inertia" und
"kgmsquared" der Einheitenname fuer "Kilogramm Meter Quadrat":.  Wählen Sie
alle vier Elemente aus und legen Sie sie im Grid aus. Klicken Sie dazu in der
Toolbar auf "Lay out in a Grid".  Fügen Sie unterhalb der Gruppe einen
vertikalen Spacer (Vertical Spacer) ein und klicken Sie bei ausgewaehltem Tab
auf "Lay out Vertically".  Das Ergebnis sollte folgendermaßen aussehen:
Speichern Sie das UI.  Öffnen Sie nun die Datei validator-setup.xml aus dem
Unterverzeichnis res.  Hier wird festgelegt, welche Zeichen in einem
Texteingabefeld vorkommen duerfen. Standardmäßig werden Dezimalzahlen erwartet.
Fügen Sie folgende Zeilen vor "</validator-setup>" ein: <double binding =
"txt_mom_poundsquarefoot" /> <double binding = "txt_mom_kgmsquared" />
Hierdurch werden die Textfelder auf double-Eingaben beschraenkt.  Speichern Sie
die Datei und öffnen Sie die Datei setup.xml.  Geben Sie folgendes Markup vor
"</setup>" ein: <group id="mom"> <unit id="txt_mom_kgmsquared"
type="factor" value="1" /> <unit id="txt_mom_poundsquarefoot" type="factor"
value=".04214011" /> </group> Die Gruppen-ID ist entsprechend der zu waehlen,
die Sie im Designer bei der Textfeldbenennung angegeben haben. Sollten Sie dem
Beispiel "mom" gefolgt sein, koennen Sie das obige Markup kopieren.  Die
Unit-ID ist der gesamte Textfeldname.  Bei type koennen Sie zwei verschiedene
Berechnungstypen angeben. Wenn nur eine einfache Multiplikation bei der
Einheitenkonversion vonnoeten ist, reicht "factor". Der erste unit-Eintrag
sollte immer die SI-Einheit sein. Das ist die Basiseinheit und traegt somit
einen "value" von 1. Bei allen anderen Einheiten ist der Faktor mit dem
multipliziert werden soll anzugeben.  Bei komplexeren Konversionsberechnungen
ist "transform" zu waehlen. Der Platzhalter %1 wird waehrend der Berechnung
durch die SI-Einheit ersetzt. Die Attribute fromSI und toSI beinhalten die
Formeln zur entsprechenden Berechnung. (Siehe dazu als Beispiel die
Temperatureinheitenkonversion.) Optional koennen Sie nun Beschreibungstexte in
die Datei info.xml im selben Verzeichnis einfuegen. Hierbei handelt es sich um
epinfaches HTML, das in eine CDATA-Sektion geschrieben werden muss.
