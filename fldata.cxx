

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>

// Demonstrate a "vertical tabbed" window dialog
// erco 05/09/08

Fl_Window       *win = 0;
Fl_Hold_Browser *bro = 0;
Fl_Group        *grp[3] = { 0,0,0 };

// CALLBACK FOR SOMEONE CLICKING ON A BROWSER TAB
void SelectGroup_CB(Fl_Widget*, void*) {
    // Show the 'selected' group
    for ( int t=0; t<3; t++ ) {
        if ( t == (bro->value()-1) ) { grp[t]->show(); }
        else                         { grp[t]->hide(); }
    }
}

int main() {
    win = new Fl_Window(600,400, "FLDATA" );

    // Browser to act as "tab selector"
    bro = new Fl_Hold_Browser(10,10,150,400-20);
    bro->add("1.Main");
    bro->add("2.Addr");
    bro->add("3.Mailbox");

    // Make three groups with different contents
    grp[0] = new Fl_Group(170,10,450-30,400-20,"Contact Name");
    grp[0]->box(FL_ENGRAVED_BOX); grp[0]->align(FL_ALIGN_INSIDE|FL_ALIGN_TOP); grp[0]->labelsize(24);
        new Fl_Input(170+140,160+00,200,20,"First:");
        new Fl_Input(170+140,160+30,200,20,"Last:");
        new Fl_Input(170+140,160+60,200,20,"Title:");
    grp[0]->end();

    grp[1] = new Fl_Group(170,10,450-30,400-20,"Contact Addr");
    grp[1]->box(FL_ENGRAVED_BOX); grp[1]->align(FL_ALIGN_INSIDE|FL_ALIGN_TOP); grp[1]->labelsize(24);
        new Fl_Input(170+140,160+00,200,20,"Street:");
        new Fl_Input(170+140,160+30,200,20,"City:");
        new Fl_Input(170+140,160+60,200,20,"State:");
        new Fl_Input(170+140,160+90,200,20,"ZIP:");
    grp[1]->end();

    grp[2] = new Fl_Group(170,10,450-30,400-20,"Contact Mailbox");
    grp[2]->box(FL_ENGRAVED_BOX); grp[2]->align(FL_ALIGN_INSIDE|FL_ALIGN_TOP); grp[2]->labelsize(24);
        new Fl_Input(170+140,160+00,200,20,"Email:");
        new Fl_Input(170+140,160+30,200,20,"Phone:");
        new Fl_Input(170+140,160+60,200,20,"Cell/Pager:");
        new Fl_Input(170+140,160+90,200,20,"ICQ:");
    grp[2]->end();

    // Set a callback for the browser, initialize first selection
    bro->callback(SelectGroup_CB);
    bro->select(1);
    SelectGroup_CB(0,0);                // (updates visible group based on our select()tion)

    //Fl_Double_Window window2(220,220,"FLCLOCK");
    win->show();
    return(Fl::run());

    return 0;
}



