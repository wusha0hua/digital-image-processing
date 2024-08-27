function varargout = edit_text_demo(varargin)
% EDIT_TEXT_DEMO MATLAB code for edit_text_demo.fig
%      EDIT_TEXT_DEMO, by itself, creates a new EDIT_TEXT_DEMO or raises the existing
%      singleton*.
%
%      H = EDIT_TEXT_DEMO returns the handle to a new EDIT_TEXT_DEMO or the handle to
%      the existing singleton*.
%
%      EDIT_TEXT_DEMO('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in EDIT_TEXT_DEMO.M with the given input arguments.
%
%      EDIT_TEXT_DEMO('Property','Value',...) creates a new EDIT_TEXT_DEMO or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before edit_text_demo_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to edit_text_demo_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help edit_text_demo

% Last Modified by GUIDE v2.5 07-Nov-2015 10:13:01

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @edit_text_demo_OpeningFcn, ...
                   'gui_OutputFcn',  @edit_text_demo_OutputFcn, ...
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


% --- Executes just before edit_text_demo is made visible.
function edit_text_demo_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to edit_text_demo (see VARARGIN)

% Choose default command line output for edit_text_demo
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes edit_text_demo wait for user response (see UIRESUME)
% uiwait(handles.figure_main);


% --- Outputs from this function are returned to the command line.
function varargout = edit_text_demo_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function my_edit_Callback(hObject, eventdata, handles)
% hObject    handle to my_edit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of my_edit as text
%        str2double(get(hObject,'String')) returns contents of my_edit as a double
str = get(hObject, 'string');
val = str2num(str);
if ~isempty(val) && (val >= 0 & val <= 1)
    set(handles.value_display, 'value', val)
end


% --- Executes during object creation, after setting all properties.
function my_edit_CreateFcn(hObject, eventdata, handles)
% hObject    handle to my_edit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on slider movement.
function value_display_Callback(hObject, eventdata, handles)
% hObject    handle to value_display (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider


% --- Executes during object creation, after setting all properties.
function value_display_CreateFcn(hObject, eventdata, handles)
% hObject    handle to value_display (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end
