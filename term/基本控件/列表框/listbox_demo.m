function varargout = listbox_demo(varargin)
% LISTBOX_DEMO MATLAB code for listbox_demo.fig
%      LISTBOX_DEMO, by itself, creates a new LISTBOX_DEMO or raises the existing
%      singleton*.
%
%      H = LISTBOX_DEMO returns the handle to a new LISTBOX_DEMO or the handle to
%      the existing singleton*.
%
%      LISTBOX_DEMO('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in LISTBOX_DEMO.M with the given input arguments.
%
%      LISTBOX_DEMO('Property','Value',...) creates a new LISTBOX_DEMO or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before listbox_demo_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to listbox_demo_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help listbox_demo

% Last Modified by GUIDE v2.5 07-Nov-2015 11:20:56

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @listbox_demo_OpeningFcn, ...
                   'gui_OutputFcn',  @listbox_demo_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before listbox_demo is made visible.
function listbox_demo_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to listbox_demo (see VARARGIN)

% Choose default command line output for listbox_demo
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes listbox_demo wait for user response (see UIRESUME)
% uiwait(handles.figure_main);


% --- Outputs from this function are returned to the command line.
function varargout = listbox_demo_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on selection change in my_listbox.
function my_listbox_Callback(hObject, eventdata, handles)
% hObject    handle to my_listbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns my_listbox contents as cell array
%        contents{get(hObject,'Value')} returns selected item from my_listbox
sel = get(handles.figure_main, 'SelectionType');
if strcmp(sel, 'open')
    str = get(hObject, 'String');
    n = get(hObject, 'Value');
    set(handles.my_static_text, 'String', str{n})
end


% --- Executes during object creation, after setting all properties.
function my_listbox_CreateFcn(hObject, eventdata, handles)
% hObject    handle to my_listbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
