<div dir="rtl" lang="he">

# מחברת ועט חלק א
רובנו משתמשים במחברות ועטים מדי יום ויודעים בדיוק איך להשתמש בהם.
למחברת יש מספר דפים ובכל דף יש מספר שורות ואורך שורה ידוע מראש.
עט, כידוע, אינו מחיק. לכן, כשרוצים למחוק משהו שכתבנו בעט, לרוב "נקשקש" על מה שנרצה למחוק.

במטלה זו נכתוב מחלקה המייצגת מחברת עם אינסוף דפים, ובכל דף אינסוף שורות. אמנם, אורך השורה ידוע מראש ועומד על 100 תווים.
המחלקה צריכה לתמוך בפונקציות הבאות:

* `'write'` - מקבלת מיקום (עמוד, שורה ועמודה), כיוון (אופקי או אנכי), ומחרוזת המייצגת את מה שצריך לכתוב, 
וכותבת את המחרוזת במחברת במקום המתאים. שימו לב, אם כבר כתבנו, או מחקנו למקום שצויין, הפונקציה תזרוק שגיאה.
* `read` - מקבלת מיקום (עמוד, שורה ועמודה), כיוון (אופקי או אנכי), ומספר תוים, קוראת את מה שכתוב במחברת במיקום הנתון ובאורך הנתון, ומחזירה מחרוזת. האות הנמצאת בכל משבצת על הלוח היא האות האחרונה שנכתבה שם.
* `erase` - מקבלת מיקום (עמוד, שורה ועמודה), כיוון (אופקי או אנכי), ומספר תוים, ומוחקת את מה שכתוב במיקום ובכיוון הרלוונטי. מאחר ואנו כותבים בעט, הפונקציה לא תמחק אלא "תקשקש" במקומות המתאימים. (תציב במקום התווים הנמצאים את התו ~)
* `show` - מקבל מספר עמוד ומציגה אותו בצורה נוחה לכתיבה, בפורמט כלשהו לפי בחירתכם

דוגמאות לפעולת המחלקה ניתן למצוא ב-[Demo.cpp](Demo.cpp).

פרטים:

* מספרי העמודים, השורות והטורים ומספר התוים הם מספרים שלמים אי-שליליים (unsigned int).
* העמוד הראשון הוא 0, השורה העליונה היא 0 והטור השמאלי הוא 0.
* בכל משבצת שלא נכתב עליה כלום, יש קו תחתי
* גודל המחברת אינו מוגבל מראש, אבל אפשר להניח שנכתוב בעמודים סמוכים זה לזה, ובכל עמוד נכתוב בשורות הקרובות אחת לשנייה.

רמזים:

* כדאי לתכנן ולחשוב על אלגוריתם יעיל לפני שמתחילים לממש.
* מומלץ לחזור על החומר שנלמד בהרצאות ולהשתמש בו.
* גם חומר שנלמד בקורס מבני נתונים יכול לעזור.


בשלב א עליכם לכתוב כותרות ובדיקות-יחידה מקיפות.
יש לבדוק את הפונקציות `'erase'`,`'write'`, `read` בלבד;
אין צורך לבדוק את הפונקציה `show`
(כיוון שלא הגדרנו את הפורמט שלה).
כיתבו את כל הקבצים הדרושים כך שהפקודות הבאות יעבדו ללא שגיאות:

<div dir='ltr'>

    make demo && ./demo
	make test && ./test

</div>

מומלץ גם להריץ:

<div dir='ltr'>

    make tidy
    make valgrind

</div>

שימו לב:
אין לשנות קבצים קיימים, אלא רק להוסיף קבצים חדשים.
מערכת הבדיקה האוטומטית מעתיקה מחדש את כל הקבצים הקיימים על-גבי הפתרון שאתם מגישים,
ולכן כל שינוי שתעשו בקבצים הקיימים יימחק.

בהצלחה
</div>

<div dir="rtl" lang="he">

# מחברת ועט חלק ב

כתבו מחלקה לניהול מחברת עם אינסוף דפים, בהתאם להוראות בחלק א.

בשלב ב עליכם לכתוב מימוש מלא. המימוש צריך לעבור את כל הבדיקות (60% מהציון):

<div dir='ltr'>

    make test
    ./test

</div>

בנוסף, הקוד צריך לעבור בהצלחה את מבחן הקריאות (20% מהציון):

<div dir='ltr'>

    make tidy

</div>

ואת מבחן הזיכרון (20% מהציון):

<div dir='ltr'>

    make valgrind

</div>

בנוסף, יש לכתוב **תוכנית ראשית** כלשהי המדגימה את הפתרון שלכם.
תוכן התוכנית לבחירתכם - תהיו יצירתיים. התוכנית לא תיבדק אוטומטית אלא רק בהצגה.

כשהגעתם למצב ששתי הפקודות רצות בלי שגיאות, תוכלו לבדוק את הציון שלכם ע"י הפקודה:

<div dir='ltr'>

    bash grade

</div>

</div>