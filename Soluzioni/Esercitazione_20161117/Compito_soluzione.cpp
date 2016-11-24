// Word Jumble
// The classic word jumble game where the player can ask for a hint

#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool game = true;
    bool defeat = false;

    int playerInput = -1; // Inizializzazione generica
    bool invalidInput = false;

    while (game)
    {
        // Introduzione
        cout << endl;
        cout << "Ti risvegli misteriosamente in un castello durante una notte buia e tempestosa...\nRialzandoti ancora confuso, noti di trovarti nell'androne principale. Le pareti ospitano schiere di antiche armature, mentre scale maestose portano a quella che deve essere la sala dove il lord del castello teneva le sue udienze secoli fa. In un angolo, sinistre scale a chiocciola scendono in profondità, mentre uno smisurato lampadario pieno di spunzoni metallici ti sovrasta minaccioso. Cosa fai?" << endl;

        // Round 1
        do
        {
            cout << "1) Esamina le armature;" << endl;
            cout << "2) Osserva l'enorme lampadario;" << endl;
            cout << "3) Scendi nei sotterranei;" << endl;
            cout << "4) Vai nel salone delle udienze;" << endl;
            cin >> playerInput;

            invalidInput = false;
            switch(playerInput)
            {
                case 1:
                    cout << "Le armature sono coperte da strati di ruggine e polvere vecchi di secoli. Le armi potevano incutere timore un tempo, ma non le corrose lame smussate che si stagliano di fronte a te. Spinto da una bizzarra curiosità, alzi la celata di un elmo e guardi dentro. Niente... Cos'altro doveva esserci? Non hai il tempo di sentirti ingenuo, perché una voce risuonante nella tua testa riecheggia dicendo: \"Questa armatura ha trovato un nuovo ospite...\" L'istante successivo, la tua volontà ha un nuovo padrone..."  << endl;    
                    defeat = true;
                    break;
                case 2:
                    cout << "Meraviglioso... puro stile gotico! Anche eccessivo forse... Vedi una scritta, un incisione... Niente di strano, ma... cosa c'è scritto...? \"La maledizione si scatenerà a chiunque poserà gli occhi su queste parole...\". Ma che vuol dire? Una versione antica di \"Scemo chi legge\"? La terribile risposta arriva dagli scricchiolii sinistri della catena che sostiene il lampadario, seguiti dall'avventarsi ineluttabile dei suoi spietati spunzoni su di te..." << endl;    
                    defeat = true;
                    break;
                case 3:
                    cout << "Un inspiegabile coraggio ti spinge a scendere le anguste scale verso i sotterranei. L'umidità opprimente si mescola ad un'aria ferma da secoli, accrescendo il tuo disagio ad ogni gradino. Finalmente la discesa ha fine e uno spettacolo terribile ti si presenta alla luce fioca di candele stranamente accese: celle arrugginite, attrezzi di tortura e tracce di sangue rappreso invadono l'ambiente. Non fai in tempo a pentirti della tua scelta che una cancello alle tue spalle si chiude e una voce metallica e ridacchiante sentenzia la tua fine: \"Ah, un nuovo prigioniero dopo tanto tempo... il mio signore sarà soddisfatto...!\"" << endl;
                    defeat = true;
                    break;
                case 4:
                    cout << "Sali lentamente le scale, i tuoi passi riecheggianti nel silenzio totale. La sala delle udienze è imponente e sfarzosa, ma allo stesso tempo vittima di una decadenza non solo causata dal tempo... Dalla parte opposta della stanza lo scranno del signore del castello sembra vuoto. Ma guardando meglio, uno strano bagliore sembra pervaderlo.\nTi avvicini.\nSei a pochi metri dallo scranno ormai e una figura spettrale appare su di esso. Un vecchio, pelle e ossa, in abiti eleganti ma consunti, ti squadra con sguardo glaciale.\n\"Chi sei!?\", chiede il fantasma. \"Perché osi profanare la mia eterna dimora?\".\nCosa rispondi?" << endl;    
                    break;
                default:
                    invalidInput = true;
                    break;
            }
        }
        while(invalidInput);

        // Round 2
        if (!defeat)
        {
            do
            {   
                cout << "1) \"Silenzio vecchio, tanto questo è solo un sogno.\"" << endl;
                cout << "2) \"Sono qui per assolverti dai tuoi peccati...\"" << endl;
                cout << "3) \"Ti sfido a duello per il diritto di governare su queste terre!\"" << endl;
                cout << "4) \"Ehm... il bagno è in fondo a destra...?\"" << endl;
                cin >> playerInput;

                invalidInput = false;
                switch(playerInput)
                {
                    case 1:
                        cout << "\"La tua impudenza sarà punita!\" Quello che accadde dopo non può essere descritto con parole umane. Gli occhi dello spettro trascinano la tua anima nel suo regno infernale, senza lasciarti alcuna speranza di rimangiarti le tue parole..." << endl;    
                        defeat = true;
                        break;
                    case 2:
                        cout << "\"Anima misericordiosa... La mia vita di eccessi e peccati aveva consumato il mio spirito e per punizione fui condannato a rimanere chiuso in questa mia gabbia di nefandezze per l'eternità. Ma ora ho il tuo perdono e posso andarmene in pace. Grazie di tutto cuore!\" Con queste sue ultime parole, lo spirito dell'antico lord del castello si dissolve nell'aria.\nTi svegli all'improvviso. Nel tuo letto, nella tua camera, nel tuo mondo. E ti chiederai sempre, per tutta la vita, se questa piccola avventura è stata davvero un sogno... oppure no..." << endl;    
                        break;
                    case 3:
                        cout << "\"Sfida accettata...\". Un cenno della mano spettrale richiama l'attenzione di una volontà immobile da lungo tempo: un'enorme armatura si avvicina a te, brandendo un'assurda lama seghettata. Hai già capito che la tua fine è giunta..." << endl;
                        defeat = true;
                        break;
                    case 4:
                        cout << "No vabbè, seri dai... da capo!" << endl;    
                        defeat = true;
                        break;
                    default:
                        invalidInput = true;
                        break;
                }
            }
            while(invalidInput);
        }

        if (defeat)
        {
            // Sconfitta
            cout << "Game Over" << endl;
            do
            {
                cout << "Vuoi ricominciare?" << endl;
                cout << "1) Certo!" << endl;
                cout << "2) No..." << endl;
                cin >> playerInput;

                invalidInput = false;
                switch(playerInput)
                {
                    case 1:
                        defeat = false;
                        break;
                    case 2:
                        game = false; // non necessario ma per chiarezza
                        break;
                    default:
                        invalidInput = true;
                        break;
                }   
            }
            while(invalidInput);
        }
        else
        {
            // Vittoria
            cout << "Congratulazioni! Hai vinto!" << endl;
            cout << "Digita un qualunque carattere per uscire" << endl;
            cin >> playerInput;
            game = false;
        }
    }
    

    return 0;
}
