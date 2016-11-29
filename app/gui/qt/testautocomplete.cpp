#include <QtTest/QtTest>

#include "sonicpiapis.h"
#include <memory>

class TestUpdateAutoCompletionList: public QObject
{
    Q_OBJECT
private slots:

    void initTestCase()
    {

    }

    void cleanupTestCase()
    {

    }

    void withEmptyContext_ListIsEmpty()
    {
        QStringList context;
        QStringList result;
        auto keywords = makeKeywordList();
        auto fxArgs = makeArgsList();
        auto synthArgs = makeArgsList();

        SonicPiAPIs::updateAutoCompletionListImpl(context, result, keywords, fxArgs, synthArgs);

        QCOMPARE(result.length(), 0);
    }
    //if (last == "sample" || last == "sample_info" || last == "sample_duration" || last == "use_sample_bpm" || last == "sample_buffer" || last == "sample_loaded?" || last == "load_sample" || last == "load_samples")
    void withSampleKeywordAndPartial_AddsSamplesMatchingPartial()
    {
        QStringList context;
        context << "sample" << "t";
        QStringList result;
        auto keywords = makeKeywordList();
        QString expectedContent("test");
        keywords[SonicPiAPIs::Sample] << expectedContent;
        auto fxArgs = makeArgsList();
        auto synthArgs = makeArgsList();

        SonicPiAPIs::updateAutoCompletionListImpl(context, result, keywords, fxArgs, synthArgs);

        QCOMPARE(result.length(), 1);
        QCOMPARE(result.first(), expectedContent);
    }

private:

    static SonicPiAPIs::KeywordList makeKeywordList() { return SonicPiAPIs::KeywordList(); }
    static SonicPiAPIs::ArgsList makeArgsList() { return SonicPiAPIs::ArgsList(); }
};


QTEST_MAIN(TestUpdateAutoCompletionList)
#include "testautocomplete.moc"
